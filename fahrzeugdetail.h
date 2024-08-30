#ifndef FAHRZEUGDETAIL_H
#define FAHRZEUGDETAIL_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlTableModel>

namespace Ui {
class FahrzeugDetail;
}

class FahrzeugDetail : public QWidget
{
    Q_OBJECT

public:
    explicit FahrzeugDetail(QWidget *parent = nullptr, int nummer = 0);
    ~FahrzeugDetail();

    //die Methoden
private:
    void datenMappen(int nummer);

    //die Slots
private slots:
    void on_buttonSchliessen_clicked();

private:
    Ui::FahrzeugDetail *ui;
    //für den Mapper
    QDataWidgetMapper *mapper;
    //für das Modell
    QSqlTableModel *modell;
};

#endif // FAHRZEUGDETAIL_H
