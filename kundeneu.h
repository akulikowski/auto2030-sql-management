#ifndef KUNDENEU_H
#define KUNDENEU_H

#include <QWidget>
//für die SQL-Klassen
#include <QtSql>

namespace Ui {
class KundeNeu;
}

class KundeNeu : public QWidget
{
    Q_OBJECT

public:
    explicit KundeNeu(QWidget *parent = nullptr);
    ~KundeNeu();

private slots:
    //die Slots
    //sie nutzen den AutoConnect-Mechanismus
    void on_buttonOK_clicked();
    void on_buttonBeenden_clicked();

private:
    Ui::KundeNeu *ui;
    //für das Modell
    QSqlTableModel *modell;
};

#endif // KUNDENEU_H
