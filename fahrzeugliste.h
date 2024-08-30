#ifndef FAHRZEUGLISTE_H
#define FAHRZEUGLISTE_H

//die Dateien einbinden
//für die SQL-Klassen
#include <QtSql>
#include <QtGui>
#include <QDialog>

//unsere Klasse erbt von QDialog
class FahrzeugListe : public QDialog
{
public:
    FahrzeugListe();
};

#endif // FAHRZEUGLISTE_H
