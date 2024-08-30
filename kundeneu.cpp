#include "kundeneu.h"
#include "ui_kundeneu.h"
//für die Messagebox
#include <QMessageBox>

KundeNeu::KundeNeu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KundeNeu)
{
    ui->setupUi(this);
    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("kunden");
}

KundeNeu::~KundeNeu()
{
    delete ui;
}

void KundeNeu::on_buttonOK_clicked()
{
    if (ui->lineEditVorname->text().isEmpty() || ui->lineEditName->text().isEmpty() ||
            ui->lineEditStrasse->text().isEmpty() || ui->lineEditPLZ->text().isEmpty() ||
            ui->lineEditOrt->text().isEmpty() || ui->lineEditTelefon->text().isEmpty())
        {
            QMessageBox::critical(this, "Fehler", "Bitte füllen Sie alle Pflichtfelder aus.");
            return;
        }


    //eine leere Zeile ergänzen
    int zeile;
    zeile = modell->rowCount();
    modell->insertRow(zeile);

    //die Daten aus dem Formular übernehmen
    modell->setData(modell->index(zeile, 1), ui->lineEditVorname->text());
    modell->setData(modell->index(zeile, 2), ui->lineEditName->text());
    modell->setData(modell->index(zeile, 3), ui->lineEditStrasse->text());
    modell->setData(modell->index(zeile, 4), ui->lineEditPLZ->text());
    modell->setData(modell->index(zeile, 5), ui->lineEditOrt->text());
    modell->setData(modell->index(zeile, 6), ui->lineEditTelefon->text());
    //die Änderungen übernehmen
    modell->submitAll();

    //eine Meldung anzeigen
    QMessageBox::information(this,"Info", "Die Daten wurden übernommen.");

    //und alle Felder wieder leeren
    ui->lineEditName->clear();
    ui->lineEditVorname->clear();
    ui->lineEditStrasse->clear();
    ui->lineEditPLZ->clear();
    ui->lineEditOrt->clear();
    ui->lineEditTelefon->clear();
}

void KundeNeu::on_buttonBeenden_clicked()
{
    //das Formular schließen
    this->close();
}
