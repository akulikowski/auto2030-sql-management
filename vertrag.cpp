#include "vertrag.h"
#include "ui_vertrag.h"

#include <QTableView>
#include <QHeaderView>
#include <QMessageBox>

//für die Detailansichten
#include <kundedetail.h>
#include <fahrzeugdetail.h>

Vertrag::Vertrag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Vertrag)
{
    ui->setupUi(this);

    //das Datum soll nicht geprüft werden
    datumPruefen = false;

    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("vertraege");

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
    fahrzeugModell->setQuery("SELECT fNummer, bezeichnung FROM fahrzeuge WHERE ausgeliehen = 0");

    //die Ansicht
    QTableView *fahrzeugAnsicht = new QTableView;
    //die Zeilen- und Spaltenköpfe ausblenden
    fahrzeugAnsicht->verticalHeader()->hide();
    fahrzeugAnsicht->horizontalHeader()->hide();

    //Modell und Ansicht für das Kombinationsfeld setzen
    ui->comboBoxFahrzeug->setModel(fahrzeugModell);
    ui->comboBoxFahrzeug->setView(fahrzeugAnsicht);

    //die Datumsfelder setzen
    ui->dateEditAusleihe->setDate(QDate::currentDate());
    ui->dateEditRueckgabe->setDate(QDate::currentDate().addDays(1));

    ui->dateEditAusleihe->setMinimumDate(QDate::currentDate());
    ui->dateEditRueckgabe->setMinimumDate(QDate::currentDate());

    //gibt es Fahrzeuge und Kunden?
    if (ui->comboBoxFahrzeug->count() == 0 || ui->comboBoxKunde->count() == 0)
    {
        //sonst geben wir eine Meldung aus und schließen das Formular wieder
        QMessageBox::critical(this,"Fehler", "Es kann keine Vermietung durchgeführt werden.");
        //die Anweisung zum Ausführen der Methode in die Warteschlange stellen
        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
    }

    //den Preis berechnen und anzeigen
    preisBerechnen();
}

Vertrag::~Vertrag()
{
    delete ui;
}

//die Slots
void Vertrag::on_buttonSpeichern_clicked()
{
    //die Markierung in der Tabelle für die Fahrzeuge setzen
    QSqlQuery query;
    query.prepare("UPDATE fahrzeuge SET ausgeliehen = 1 WHERE fNummer = ?");
    query.addBindValue(ui->comboBoxFahrzeug->currentText().toInt());
    if (!query.exec()) {
        QMessageBox::critical(this, "Fehler", "Das Fahrzeug konnte nicht als ausgeliehen markiert werden.");
    }



    //den Preis berechnen
    preisBerechnen();

    //eine leere Zeile in der Tabelle ergänzen
    int zeile;
    zeile = modell->rowCount();
    modell->insertRow(zeile);

    //die Daten aus dem Formular übernehmen
    modell->setData(modell->index(zeile, 1), ui->dateEditAusleihe->date().toString("dd.MM.yy"));
    modell->setData(modell->index(zeile, 2), ui->dateEditRueckgabe->date().toString("dd.MM.yy"));
    modell->setData(modell->index(zeile, 3), ui->lineEditPreis->text());
    modell->setData(modell->index(zeile, 4), ui->comboBoxKunde->currentText().toInt());
    modell->setData(modell->index(zeile, 5), ui->comboBoxFahrzeug->currentText().toInt());
    //die Änderungen übernehmen
    modell->submitAll();

    //eine Meldung anzeigen
    QMessageBox::information(this,"Info", "Der Vertrag wurde erstellt.");

    //das Formular schließen
    this->close();
}

void Vertrag::on_buttonAbbrechen_clicked()
{
    //das Formular schließen
    this->close();
}

void Vertrag::on_buttonKundeDetail_clicked() {
    int kNummer = ui->comboBoxKunde->currentText().toInt();
    KundeDetail *kundeDetail = new KundeDetail(nullptr, kNummer);
    kundeDetail->show();
}

void Vertrag::on_buttonFahrzeugDetail_clicked() {
    int fNummer = ui->comboBoxFahrzeug->currentText().toInt();
    FahrzeugDetail *fahrzeugDetail = new FahrzeugDetail(nullptr, fNummer);
    fahrzeugDetail->show();
}

void Vertrag::preisBerechnen()
{
    //zum Speichern des Preises pro Tag
    float preisProTag;
    //für die Differenz der Tage
    int anzahlTage;

    //den Preis beschaffen
    QSqlQuery query;
    query.prepare("SELECT preisProTag FROM fahrzeuge WHERE fnummer = ?");
    query.addBindValue(ui->comboBoxFahrzeug->currentText().toInt());
    if (query.exec() && query.next()) {
        preisProTag = query.value(0).toFloat();
    } else {
        QMessageBox::warning(this, "Fehler", "Preis konnte nicht ermittelt werden.");
        return;
    }

    //die Differenz der Tage berechnen
    //erst beschaffen wir uns das Datum
    QDate ausleihdatum = ui->dateEditAusleihe->date();
    QDate rueckgabedatum = ui->dateEditRueckgabe->date();
    //die Differenz
    anzahlTage = ausleihdatum.daysTo(rueckgabedatum);
    //und noch 1 addieren
    anzahlTage = anzahlTage + 1;

    //haben wir ein gültiges Datum und sollen Prüfungen erfolgen?
    //dann ist anzahlTage mindestens 1 und datumPruefen true
    if (anzahlTage < 1 && datumPruefen == true)
    {
        //das Datum ist nicht gültig
        QMessageBox::critical(this,"Fehler", "Die Datumsangaben sind nicht gültig.\nSie werden neu gesetzt.");
        //die Datumsfelder auf Standardwerte setzen
        ui->dateEditAusleihe->setDate(QDate::currentDate());
        ui->dateEditRueckgabe->setDate(QDate::currentDate().addDays(1));
        //die Anzahl der Tage neu setzen
        anzahlTage = 1;
    }

    //den berechneten Wert in das Feld setzen
    ui->lineEditPreis->setText(QString::number(preisProTag * anzahlTage));
}

//die Slots zum Aktualisieren des Preises
void Vertrag::on_comboBoxFahrzeug_activated()
{
    preisBerechnen();
}

void Vertrag::on_dateEditAusleihe_dateChanged()
{
    preisBerechnen();
    datumPruefen = true;
}

void Vertrag::on_dateEditRueckgabe_dateChanged()
{
    preisBerechnen();
    datumPruefen = true;
}
