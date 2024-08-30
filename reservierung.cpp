#include "reservierung.h"
#include "ui_reservierung.h"

#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>

//für die Detailansichten
#include <kundedetail.h>
#include <fahrzeugdetail.h>

Reservierung::Reservierung(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reservierung)
{
    ui->setupUi(this);
    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("reservierungen");

    //die Daten für die Kombinationsfelder beschaffen
    //für die Kunden
    QSqlQueryModel *kundenModell = new QSqlQueryModel;
    //die Abfrage ausführen
    kundenModell->setQuery("SELECT kNummer, nachname FROM kunden");

    //die Ansicht
    QTableView *kundenAnsicht = new QTableView;
    //die Zeilen- und Spaltenköpfe ausblenden
    kundenAnsicht->verticalHeader()->hide();
    kundenAnsicht->horizontalHeader()->hide();

    //Modell und Ansicht für das Kombinationsfeld setzen
    ui->comboBoxKunde->setModel(kundenModell);
    ui->comboBoxKunde->setView(kundenAnsicht);

    //für die Fahrzeuge
    QSqlQueryModel *fahrzeugModell = new QSqlQueryModel;
    //die Abfrage ausführen
    fahrzeugModell->setQuery("SELECT fNummer, bezeichnung FROM fahrzeuge WHERE ausgeliehen = 1");

    //die Ansicht
    QTableView *fahrzeugAnsicht = new QTableView;
    //die Zeilen- und Spaltenköpfe ausblenden
    fahrzeugAnsicht->verticalHeader()->hide();
    fahrzeugAnsicht->horizontalHeader()->hide();

    //Modell und Ansicht für das Kombinationsfeld setzen
    ui->comboBoxFahrzeug->setModel(fahrzeugModell);
    ui->comboBoxFahrzeug->setView(fahrzeugAnsicht);

    //das Datumsfeld setzen
    ui->dateEditGueltigBis->setDate(QDate::currentDate().addDays(30));

    //gibt es Fahrzeuge und Kunden?
    if (ui->comboBoxFahrzeug->count() == 0 || ui->comboBoxKunde->count() == 0)
    {
        //sonst geben wir eine Meldung aus und schließen das Formular wieder
        QMessageBox::critical(this,"Fehler", "Es kann keine Reservierung durchgeführt werden.");
        //die Anweisung zum Ausführen der Methode in die Warteschlange stellen
        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
    }
}

Reservierung::~Reservierung()
{
    delete ui;
}

//die Slots
void Reservierung::on_buttonUebernehmen_clicked()
{
    //eine leere Zeile in der Tabelle ergänzen
    int zeile;
    zeile = modell->rowCount();
    modell->insertRow(zeile);

    //die Daten aus dem Formular übernehmen
    modell->setData(modell->index(zeile, 1), ui->dateEditGueltigBis->date().toString("dd.MM.yyyy"));
    modell->setData(modell->index(zeile, 2), ui->comboBoxKunde->currentText().toInt());
    modell->setData(modell->index(zeile, 3), ui->comboBoxFahrzeug->currentText().toInt());
    //die Änderungen übernehmen
    modell->submitAll();

    //eine Meldung anzeigen
    QMessageBox::information(this,"Info", "Die Reservierung wurde angelegt.");

    //das Formular schließen
    this->close();
}

void Reservierung::on_buttonAbbrechen_clicked()
{
    //das Formular schließen
    this->close();
}

void Reservierung::on_buttonKundeDetail_clicked() {
    int kNummer = ui->comboBoxKunde->currentText().toInt();
    KundeDetail *kundeDetail = new KundeDetail(nullptr, kNummer);
    kundeDetail->show();
}

void Reservierung::on_buttonFahrzeugDetail_clicked() {
    int fNummer = ui->comboBoxFahrzeug->currentText().toInt();
    FahrzeugDetail *fahrzeugDetail = new FahrzeugDetail(nullptr, fNummer);
    fahrzeugDetail->show();
}
