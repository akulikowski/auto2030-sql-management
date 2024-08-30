#include "fahrzeugneu.h"
#include "ui_fahrzeugneu.h"
//für die Messagebox
#include <QMessageBox>

FahrzeugNeu::FahrzeugNeu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FahrzeugNeu)
{
    ui->setupUi(this);
    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("fahrzeuge");
}

FahrzeugNeu::~FahrzeugNeu()
{
    delete ui;
}

//die Slots
void FahrzeugNeu::on_buttonOK_clicked()
{
    //eine leere Zeile ergänzen
    int zeile;
    zeile = modell->rowCount();
    modell->insertRow(zeile);

    //die Daten aus dem Formular übernehmen
    modell->setData(modell->index(zeile, 1), ui->lineEditBezeichnung->text());
    modell->setData(modell->index(zeile, 2), ui->lineEditKennzeichen->text());
    modell->setData(modell->index(zeile, 3), ui->lineEditPreisProTag->text().toFloat());
    modell->setData(modell->index(zeile, 4), ui->lineEditTyp->text());
    //ausgeliehen ist erst einmal 0
    modell->setData(modell->index(zeile, 5), 0);
    //die Änderungen übernehmen
    modell->submitAll();

    //eine Meldung anzeigen
    QMessageBox::information(this,"Info", "Die Daten wurden übernommen.");

    //und alle Felder wieder leeren
    ui->lineEditBezeichnung->clear();
    ui->lineEditKennzeichen->clear();
    ui->lineEditPreisProTag->clear();
    ui->lineEditTyp->clear();
}

void FahrzeugNeu::on_buttonBeenden_clicked()
{
    //das Formular schließen
    this->close();
}
