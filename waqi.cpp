#include "waqi.h"

waqi::waqi()
{

}

void waqi::set_url(QString url){
    qurl = QUrl(url);
}

QByteArray waqi::get(QUrl url){

    QNetworkRequest requete(url);

    //    Pour la gestion de la connexion sécurisée SSL (HTTPS)
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);

    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;
}

double waqi::get_air(QString ville, QString token){

    QUrl url = qurl;
    QString path = url.url() + "/feed/" + ville + "/?token=" + token;
    url = QUrl(path);

    //la reponse de l'api est stockée dans un json
    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url));

    //on transforme le json en objet json
    QJsonObject objetJSON = documentJSON.object();

    qDebug() << objetJSON.value("data").toObject().value("aqi");
    QJsonValue dataJSON = objetJSON.value("data");
    //qDebug()<< dataJSON.value("aqi").toDouble();
    //on cherche la clé "brightness" et on vérifie que la valeur est un double
    if(objetJSON.value("data").toObject().value("aqi").isDouble())
    {
        return objetJSON.value("data").toObject().value("aqi").toDouble();
    }
    else
    {
        return 0;
    }
}

QByteArray waqi::get_json_air(QString ville, QString token){

    QUrl url = qurl;
    QString path = url.url() + "/feed/" + ville + "/?token=d9636de539c0cc32e3771e378fd51527b70526f1";
    url = QUrl(path);

    return get(url);
}
