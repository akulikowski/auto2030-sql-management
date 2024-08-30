#include "rueckgabe.h"
#include "ui_rueckgabe.h"

#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>

//für die Detailansicht
#include <fahrzeugdetail.h>



Rueckgabe::Rueckgabe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rueckgabe)
{
    ui->setupUi(this);
    //das Kombinationsfeld für die Fahrzeuge füllen
    QSqlQueryModel *fahrzeugModell = new QSqlQueryModel;
    //die Abfrage ausführen
    fahrzeugModell->setQuery("SELECT fNummer, bezeichnung FROM fahrzeuge WHERE ausgeliehen = 1");

    //die Ansicht
    QTableView *fahrzeugAnsicht = new QTableView;
    //die Zeilen- und Spaltenköpfe ausblenden
    fahrzeugAnsicht->verticalHeader()->hide();
    fahrzeugAnsicht->horizontalHeader()->hide();

    //Modell und Ansicht für das Kombinationsfeld setzen
    ui->comboBoxRueckgabe->setModel(fahrzeugModell);
    ui->comboBoxRueckgabe->setView(fahrzeugAnsicht);

    //gibt es Fahrzeuge?
    if (ui->comboBoxRueckgabe->count() == 0)
    {
        //sonst geben wir eine Meldung aus und schließen das Formular wieder
        QMessageBox::critical(this,"Fehler", "Es kann keine Rückgabe durchgeführt werden.");
        //die Anweisung zum Ausführen der Methode in die Warteschlange stellen
        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
    }
}

Rueckgabe::~Rueckgabe()
{
    delete ui;
}

//die Slots

void Rueckgabe::on_buttonUebernehmen_clicked()
{
    //die Markierung in der Tabelle für die Fahrzeuge setzen
    //die Abfrage erstellen
    QSqlQuery query;
    query.prepare("UPDATE fahrzeuge SET ausgeliehen = 0 WHERE fNummer = ?");
    query.addBindValue(ui->comboBoxRueckgabe->currentText().toInt());
    if (!query.exec()) {
        QMessageBox::critical(this, "Fehler", "Das Fahrzeug konnte nicht als zurückgegeben markiert werden.");
    } else {
        //eine Meldung anzeigen
        QMessageBox::information(this,"Info", "Die Rückgabe wurde durchgeführt.");
        //das Formular schließen
        this->close();
    }

    //das Formular schließen
    this->close();
}

void Rueckgabe::on_buttonAbbrechen_clicked()
{
    //das Formular schließen
    this->close();
}

void Rueckgabe::on_buttonFahrzeugDetail_clicked() {
    int fNummer = ui->comboBoxRueckgabe->currentText().toInt();
    FahrzeugDetail *fahrzeugDetail = new FahrzeugDetail(nullptr, fNummer);
    fahrzeugDetail->show();
}



