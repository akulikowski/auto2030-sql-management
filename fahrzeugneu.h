#ifndef FAHRZEUGNEU_H
#define FAHRZEUGNEU_H

#include <QWidget>
//für die SQL-Klassen
#include <QtSql>

namespace Ui {
class FahrzeugNeu;
}

class FahrzeugNeu : public QWidget
{
    Q_OBJECT

public:
    explicit FahrzeugNeu(QWidget *parent = nullptr);
    ~FahrzeugNeu();

private slots:
    //die Slots
    //sie nutzen den AutoConnect-Mechanismus
    void on_buttonOK_clicked();
    void on_buttonBeenden_clicked();

private:
    Ui::FahrzeugNeu *ui;
    //für das Modell
    QSqlTableModel *modell;
};

#endif // FAHRZEUGNEU_H
