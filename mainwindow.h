#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//für die SQL-Klassen
//außerdem muss in der Projektdatei der Eintrag sql hinzugefügt werden
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //stellt die Verbindung zur Datenbank her
    bool dbVerbinden();

private:
    Ui::MainWindow *ui;
    //steht die Verbindung zur Datenbank?
    bool dbVerbunden;
    //für die Datenbank
    QSqlDatabase datenbank;

//die überschriebene Methode beim Schließen des Fensters
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    //die Slots
    //sie nutzen den AutoConnect-Mechanismus
    void on_buttonListenAnzeigeKunde_clicked();
    void on_buttonEinzelAnzeigeKunde_clicked();
    void on_buttonNeuerEintragKunde_clicked();
    void on_buttonListenAnzeigeFahrzeug_clicked();
    void on_buttonEinzelAnzeigeFahrzeug_clicked();
    void on_buttonNeuerEintragFahrzeug_clicked();
    void on_buttonAusleihe_clicked();
    void on_buttonRueckgabe_clicked();
    void on_buttonReservierung_clicked();
};
#endif // MAINWINDOW_H
