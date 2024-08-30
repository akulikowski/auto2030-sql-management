#ifndef VERTRAG_H
#define VERTRAG_H

#include <QWidget>
//für die SQL-Klassen
#include <QtSql>

namespace Ui {
class Vertrag;
}

class Vertrag : public QWidget
{
    Q_OBJECT

public:
    explicit Vertrag(QWidget *parent = nullptr);
    ~Vertrag();

private:
    void preisBerechnen();

private slots:
    //die Slots
    //sie nutzen den AutoConnect-Mechanismus
    void on_buttonSpeichern_clicked();
    void on_buttonAbbrechen_clicked();
    void on_buttonKundeDetail_clicked();
    void on_buttonFahrzeugDetail_clicked();
    void on_comboBoxFahrzeug_activated();
    void on_dateEditAusleihe_dateChanged();
    void on_dateEditRueckgabe_dateChanged();

private:
    Ui::Vertrag *ui;
    //für das Modell
    QSqlTableModel *modell;
    //zum Markieren für Änderungen
    bool datumPruefen;
};

#endif // VERTRAG_H
