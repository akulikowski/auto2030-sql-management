#include "kundedetail.h"
#include "ui_kundedetail.h"

KundeDetail::KundeDetail(QWidget *parent, int nummer) :
    QWidget(parent),
    ui(new Ui::KundeDetail)
{
    ui->setupUi(this);
    datenMappen(nummer);
}

KundeDetail::~KundeDetail()
{
    delete ui;
}

void KundeDetail::datenMappen(int nummer)
{
    //das Modell erstellen
    modell = new QSqlTableModel(this);
    //die Tabelle setzen
    modell->setTable("kunden");
    //den Filter setzen
    QString filter = "kNummer = " + QString::number(nummer);
    modell->setFilter(filter);
    //die Daten beschaffen
    modell->select();

    //die Verbindungen zwischen den Widgets und den Daten herstellen
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(modell);
    mapper->addMapping(ui->lineEditVorname, 1);
    mapper->addMapping(ui->lineEditName, 2);
    mapper->addMapping(ui->lineEditStrasse, 3);
    mapper->addMapping(ui->lineEditPLZ, 4);
    mapper->addMapping(ui->lineEditOrt, 5);
    mapper->addMapping(ui->lineEditTelefon, 6);

    //zum ersten Datensatz gehen
    mapper->toFirst();
}

void KundeDetail::on_buttonSchliessen_clicked()
{
    //das Formular schließen
    this->close();
}

