#include "fahrzeugeinzel.h"
#include "ui_fahrzeugeinzel.h"
#include <QtSql>

//der Konstruktor
//er verbindet das Formular mit der Oberfläche und stellt die Verbindungen her
FahrzeugEinzel::FahrzeugEinzel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FahrzeugEinzel)
{
    ui->setupUi(this);
    verbindungenHerstellen();
    datenMappen();
}

FahrzeugEinzel::~FahrzeugEinzel()
{
    delete ui;
}

void FahrzeugEinzel::verbindungenHerstellen()
{
    //die Verbindungen herstellen
    connect(ui->actionGanz_nach_vorne, SIGNAL(triggered(bool)), this, SLOT(ganzNachVorne()));
    connect(ui->actionEinen_nach_vorne, SIGNAL(triggered(bool)), this, SLOT(einenNachVorne()));
    connect(ui->actionEinen_nach_hinten, SIGNAL(triggered(bool)), this, SLOT(einenNachHinten()));
    connect(ui->actionGanz_nach_hinten, SIGNAL(triggered(bool)), this, SLOT(ganzNachHinten()));
    connect(ui->actionL_schen, SIGNAL(triggered(bool)), this, SLOT(loeschen()));
}

void FahrzeugEinzel::datenMappen()
{
    //das Modell erstellen
    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("fahrzeuge");
    //die Daten beschaffen
    modell->select();

    //die Verbindungen zwischen den Widgets und den Daten herstellen
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(modell);
    mapper->addMapping(ui->lineEditID, 0);
    mapper->addMapping(ui->lineEditBezeichnung, 1);
    mapper->addMapping(ui->lineEditKennzeichen, 2);
    mapper->addMapping(ui->lineEditPreisProTag, 3);
    mapper->addMapping(ui->lineEditTyp, 4);

    //Änderungen sollen automatisch übernommen werden
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    //zum ersten Datensatz gehen
    mapper->toFirst();
}

//die Slots
//ganz nach vorne springen
void FahrzeugEinzel::ganzNachVorne()
{
    mapper->toFirst();
}

//einen nach vorne springen
void FahrzeugEinzel::einenNachVorne()
{
    mapper->toPrevious();
}

//einen nach hinten springen
void FahrzeugEinzel::einenNachHinten()
{
    mapper->toNext();
}

//ganz nach hinten springen
void FahrzeugEinzel::ganzNachHinten()
{
    mapper->toLast();
}

//einen Datensatz löschen
void FahrzeugEinzel::loeschen()
{
    //den aktuellen Index merken
    int index = mapper->currentIndex();
    //den Eintrag löschen
    modell->removeRow(mapper->currentIndex());
    //die Änderungen übernehmen
    mapper->submit();
    //die Daten neu beschaffen
    modell->select();
    //wieder zum ursprünglichen Datensatz gehen
    //aber nur dann, wenn nicht der letzte gelöscht wurde
    //wenn der letzte Datensatz gelöscht wurde, gehen wir zum neuen "letzten"
    if (index < modell->rowCount())
        mapper->setCurrentIndex(index);
    else
        mapper->toLast();
}
