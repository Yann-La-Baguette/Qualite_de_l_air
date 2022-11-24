#ifndef WAQI_H
#define WAQI_H

#include <QNetworkReply>            ///@include QNetworkReply
#include <QNetworkAccessManager>    ///@include QNetworkAccessManager
#include <QNetworkRequest>          ///@include QNetworkRequest
#include <QUrl>                     ///@include QUrl
#include <QtGui>                    ///@include QtGui
#include <QMessageBox>              ///@include QMessageBox
#include <QStringList>              ///@include QStringList

class waqi{     ///@class waqi

public:
    /**
     * @brief waqi \n
     * Constructeur
     */
    waqi();

    /**
     * @brief set_url \n
     * Crée la racine de l'url (https://waqi.info/)
     * @param url
     */
    void set_url(QString url);

    /**
     * @brief get_air \n
     * Envoi du line avec get \n
     * Récupération de la donnée AQI dans le json
     * @param ville
     * @param token
     * @return Donnée AQI
     */
    double get_air(QString ville, QString token);

    /**
     * @brief get_json_air \n
     * Récupère le fichier json
     * @param ville
     * @param token
     * @return Fichier json
     */
    QByteArray get_json_air(QString ville, QString token);

    /**
     * @brief get_station \n
     * Récupère le nom des stations du json de recherche
     * @param ville
     * @param token
     * @return QStringList des stations
     */
    QStringList get_station(QString ville, QString token);

    /**
     * @brief get_station_json \n
     * Récupère fichier json
     * @param ville
     * @param token
     * @return Fichier json de recherche
     */
    QByteArray get_station_json(QString ville, QString token);

    /**
     * @brief get_air_station
     * @param station
     * @return AQI station choisie
     */
    double get_air_station(double station);

private:
    /**
     * @brief qurl \n
     * URL à utiliser
     */
    QUrl qurl;

    /**
     * @brief get
     * @param url
     * @return Fichier json
     */
    QByteArray get(QUrl url);

    /**
     * @brief m
     */
    QNetworkAccessManager m;

    /**
     * @brief objetJSON
     */
    QJsonObject objetJSON;

};

#endif // WAQI_H
