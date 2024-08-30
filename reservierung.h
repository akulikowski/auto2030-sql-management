#ifndef RESERVIERUNG_H
#define RESERVIERUNG_H

#include <QWidget>
//für die SQL-Klassen
#include <QtSql>

namespace Ui {
class Reservierung;
}

class Reservierung : public QWidget
{
    Q_OBJECT

public:
    explicit Reservierung(QWidget *parent = nullptr);
    ~Reservierung();

private slots:
    //die Slots
    //sie nutzen den AutoConnect-Mechanismus
    void on_buttonUebernehmen_clicked();
    void on_buttonAbbrechen_clicked();
    void on_buttonKundeDetail_clicked();
    void on_buttonFahrzeugDetail_clicked();

private:
    Ui::Reservierung *ui;
    //für das Modell
    QSqlTableModel *modell;
};

#endif // RESERVIERUNG_H
