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

    switch(ui->Ville->currentIndex()){
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


    QString token = ui->token->text();
    air.set_url("https://api.waqi.info");
    QJsonDocument documentJSON = QJsonDocument::fromJson(air.get_json_air(ville, token));
    //qDebug() << documentJSON;
    double qualite_air = air.get_air(ville, token);
    ui->AirTextBrowser->setText(documentJSON.toJson());
    ui->AQIBox->setValue(qualite_air);


    if(qualite_air<51){
        ui->AQIBox->setStyleSheet("background-color: green");
    }
    else if(qualite_air>50 && qualite_air<101){
        ui->AQIBox->setStyleSheet("background-color: yellow");
    }
    else if(qualite_air>100 && qualite_air<151){
        ui->AQIBox->setStyleSheet("background-color: orange");
    }
    else if(qualite_air>150 && qualite_air<201){
        ui->AQIBox->setStyleSheet("background-color: pink");
    }
    else if(qualite_air>200 && qualite_air<301){
        ui->AQIBox->setStyleSheet("background-color: purple");
    }
    else if(qualite_air>300){
        ui->AQIBox->setStyleSheet("background-color: red");
    }


    ui->Ville->setEnabled(true);
}

void MainWindow::station(){

    QString station;

    station = ui->stationLineEdit->text();

    QString token = ui->token->text();
    air.set_url("https://api.waqi.info");
    QJsonDocument documentJSON = QJsonDocument::fromJson(air.get_station_json(station, token));
    //qDebug() << documentJSON;
    QStringList Liste;
    Liste = air.get_station(station, token);
    ui->AirTextBrowser->setText(documentJSON.toJson());

    ui->choixStationCombo->clear();

    for(int i=0 ; i<Liste.size() ; i++){
        ui->choixStationCombo->addItem(Liste[i]);
    }
}

void MainWindow::choix_station(){

    ui->choixStationCombo->currentIndex();



}
