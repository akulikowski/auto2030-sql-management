#include "fahrzeugdetail.h"
#include "ui_fahrzeugdetail.h"

FahrzeugDetail::FahrzeugDetail(QWidget *parent, int nummer) :
    QWidget(parent),
    ui(new Ui::FahrzeugDetail)
{
    ui->setupUi(this);
    datenMappen(nummer);
}

FahrzeugDetail::~FahrzeugDetail()
{
    delete ui;
}

void FahrzeugDetail::datenMappen(int nummer)
{
    //das Modell erstellen
    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("fahrzeuge");
    //den Filter setzen
    QString filter = "fNummer = " + QString::number(nummer);
    modell->setFilter(filter);
    //die Daten beschaffen
    modell->select();

    //die Verbindungen zwischen den Widgets und den Daten herstellen
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(modell);
    mapper->addMapping(ui->lineEditBezeichnung, 1);
    mapper->addMapping(ui->lineEditKennzeichen, 2);
    mapper->addMapping(ui->lineEditPreisProTag, 3);
    mapper->addMapping(ui->lineEditTyp, 4);

    //zum ersten Datensatz gehen
    mapper->toFirst();
}

void FahrzeugDetail::on_buttonSchliessen_clicked()
{
    //das Formular schließen
    this->close();
}

