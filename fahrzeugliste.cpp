#include "fahrzeugliste.h"
#include <QTableView>

//der Konstruktor
//er erstellt den kompletten Inhalt
FahrzeugListe::FahrzeugListe()
{
    //den Fenstertitel setzen
    setWindowTitle("Listenanzeige Fahrzeuge");
    //das Modell erstellen
    QSqlTableModel *modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("fahrzeuge");
    //die Texte für die Spaltenköpfe setzen
    modell->setHeaderData(1, Qt::Horizontal, "Bezeichnung");
    modell->setHeaderData(2, Qt::Horizontal, "Kennzeichen");
    modell->setHeaderData(3, Qt::Horizontal, "Preis pro Tag");
    modell->setHeaderData(4, Qt::Horizontal, "Typ");
    //die Daten beschaffen
    modell->select();

    //die TableView erstellen
    QTableView *ansicht = new QTableView(this);
    //mit dem Modell verbinden
    ansicht->setModel(modell);
    //die Spalte für die ID ausblenden
    ansicht->hideColumn(0);
    //und auch die Spalte mit dem Status ausgeliehen
    ansicht->hideColumn(5);
    //die Breite der Spalten an den Inhalt anpassen
    ansicht->resizeColumnsToContents();
    //die Größe setzen
    ansicht->resize(500,300);
}
