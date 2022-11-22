#ifndef WAQI_H
#define WAQI_H

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>
#include <QStringList>

class waqi{

public:
    waqi();
    void set_url(QString url);

    double get_air(QString ville, QString token);
    QByteArray get_json_air(QString ville, QString token);

    QStringList get_station(QString ville, QString token);
    QByteArray get_station_json(QString ville, QString token);
    double get_air_station(QString station, QString token);

private:
    QUrl qurl;
    QByteArray get(QUrl url);
    QNetworkAccessManager m;

};

#endif // WAQI_H
