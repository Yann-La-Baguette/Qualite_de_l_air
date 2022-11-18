#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::meteo(){

    QString ville;

    switch(ui->Meteo->currentIndex()){
        case 0:
            ville = "clermont-ferrand";
            break;

        case 1:
            ville = "paris";
            break;

        case 2:
            ville = "lyon";
            break;

        case 3:
            ville = "marseille";
            break;

        case 4:
            ville = "londres";
            break;

        case 5:
            ville = "new-york";
            break;
    }



    air.set_url("https://api.waqi.info");
    QJsonDocument documentJSON = QJsonDocument::fromJson(air.get_json_air(ville, "d9636de539c0cc32e3771e378fd51527b70526f1"));
    //qDebug() << documentJSON;
    double qualite_air = air.get_air(ville, "d9636de539c0cc32e3771e378fd51527b70526f1");
    ui->AirTextBrowser->setText(documentJSON.toJson());
    ui->AQIBox->setValue(qualite_air);

    ui->Meteo->setEnabled(true);
}
