#ifndef KUNDELISTE_H
#define KUNDELISTE_H

//die Dateien einbinden
//für die SQL-Klassen
#include <QtSql>
#include <QtGui>
#include <QDialog>

//unsere Klasse erbt von QDialog
class KundeListe : public QDialog
{
public:
    //der Konstruktor
    KundeListe();
};

#endif // KUNDELISTE_H
