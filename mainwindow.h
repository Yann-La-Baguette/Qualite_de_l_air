///@author Yann Di Padova
///@date 24/11/2022

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>              ///@include QMainWindow
#include <QNetworkReply>            ///@include QNetworkReply
#include <QNetworkAccessManager>    ///@include QNetworkAccessManager
#include <QNetworkRequest>          ///@include QNetworkRequest
#include <QUrl>                     ///@include QUrl
#include <QtGui>                    ///@include QtGui
#include <QMessageBox>              ///@include QMessageBox
#include <QStringList>              ///@include QStringList

#include "waqi.h"                   ///@include waqi.h

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow   ///@class MainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow \n
     * Constructeur
     * @param parent
     *
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructeur
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    waqi air;

private slots:

    /**
     * @brief meteo \n
     * Génére un lien en fonction du choix de la ville \n
     * Récupère les données avec ce lien \n
     * Affiche le json récupéré \n
     * Affiche l'aqi
     */
    void meteo();

    /**
     * @brief station \n
     * Génére un lien pour rechercher les stations en fonction du mot clé \n
     * Affiche les résultats de la recherche dans un combo box
     */
    void station();

    /**
     * @brief choix_station \n
     * Affiche les données récupérées après avoir choisi la station \n
     */
    void choix_station();
};
#endif // MAINWINDOW_H
