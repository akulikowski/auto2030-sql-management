#ifndef RUECKGABE_H
#define RUECKGABE_H

#include <QWidget>
//für die SQL-Klassen
#include <QtSql>

namespace Ui {
class Rueckgabe;
}

class Rueckgabe : public QWidget
{
    Q_OBJECT

public:
    explicit Rueckgabe(QWidget *parent = nullptr);
    ~Rueckgabe();

private slots:
    //die Slots
    //sie nutzen den AutoConnect-Mechanismus
    void on_buttonUebernehmen_clicked();
    void on_buttonAbbrechen_clicked();
    void on_buttonFahrzeugDetail_clicked();

private:
    Ui::Rueckgabe *ui;
};

#endif // RUECKGABE_H
