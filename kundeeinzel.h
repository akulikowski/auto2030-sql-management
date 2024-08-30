#ifndef KUNDEEINZEL_H
#define KUNDEEINZEL_H

#include <QMainWindow>
#include <QDataWidgetMapper>
#include <QSqlTableModel>

namespace Ui {
class KundeEinzel;
}

class KundeEinzel : public QMainWindow
{
    Q_OBJECT

public:
    explicit KundeEinzel(QWidget *parent = nullptr);
    ~KundeEinzel();
    void verbindungenHerstellen();
    void datenMappen();

private slots:
    //die Slots
    void ganzNachVorne();
    void einenNachVorne();
    void ganzNachHinten();
    void einenNachHinten();
    void loeschen();
    void checkAndSubmit();
    void submitWithoutCheck();


private:
    Ui::KundeEinzel *ui;
    //für den Mapper
    QDataWidgetMapper *mapper;
    //für das Modell
    QSqlTableModel *modell;
};

#endif // KUNDEEINZEL_H
