#ifndef WAQI_H
#define WAQI_H

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>

class waqi
{
public:
    waqi();
    void set_url(QString url);
    double get_air(QString ville, QString token);
    QByteArray get_json_air(QString ville, QString token);

private:
    QUrl qurl;
    QByteArray get(QUrl url);
    QNetworkAccessManager m;
};

#endif // WAQI_H
