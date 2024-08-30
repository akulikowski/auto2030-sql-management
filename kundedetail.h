#ifndef KUNDEDETAIL_H
#define KUNDEDETAIL_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlTableModel>

namespace Ui {
class KundeDetail;
}

class KundeDetail : public QWidget
{
    Q_OBJECT

public:
    explicit KundeDetail(QWidget *parent = nullptr, int nummer = 0);
    ~KundeDetail();

    //die Methoden
private:
    void datenMappen(int nummer);

    //die Slots
private slots:
    void on_buttonSchliessen_clicked();

private:
    Ui::KundeDetail *ui;
    //für den Mapper
    QDataWidgetMapper *mapper;
    //für das Modell
    QSqlTableModel *modell;
};

#endif // KUNDEDETAIL_H
