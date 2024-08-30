#ifndef FAHRZEUGEINZEL_H
#define FAHRZEUGEINZEL_H

#include <QMainWindow>
#include <QDataWidgetMapper>
#include <QSqlTableModel>

namespace Ui {
class FahrzeugEinzel;
}

class FahrzeugEinzel : public QMainWindow
{
    Q_OBJECT

public:
    explicit FahrzeugEinzel(QWidget *parent = nullptr);
    ~FahrzeugEinzel();
    void verbindungenHerstellen();
    void datenMappen();

private slots:
    //die Slots
    void ganzNachVorne();
    void einenNachVorne();
    void ganzNachHinten();
    void einenNachHinten();
    void loeschen();

private:
    Ui::FahrzeugEinzel *ui;
    //für den Mapper
    QDataWidgetMapper *mapper;
    //für das Modell
    QSqlTableModel *modell;
};

#endif // FAHRZEUGEINZEL_H
