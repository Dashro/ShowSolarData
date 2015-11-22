#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H
#include <QtWebSockets/QWebSocket>
#include <QtCore>
#include "Data/Data.h"

class CWebSocketClient : public QObject
{
	Q_OBJECT

public:
	CWebSocketClient(QUrl url, QObject *parent = 0);
	~CWebSocketClient();

	void connectToServer(QUrl url);


signals:
	void serverDisconnected();
	void serverConnected(QString);
	void recievedInitialScript(QJsonObject);
	void recievedDataScript(QJsonObject);

private slots:
	void resetSocket();
	void onConnected();
	void onConnectionTimeout();
	void onTextMessageReceived(QString message);
	void onBinaryMessageReceived(QByteArray message);

private:
	QTimer				*connection_Timer;

	QWebSocket			m_webSocket;
	QUrl				m_url;
};

#endif // WEBSOCKETCLIENT_H
