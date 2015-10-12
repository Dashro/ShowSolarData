#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H
#include <QtWebSockets/QWebSocket>
#include <QObject>
#include "Data/Data.h"

class CWebSocketClient : public QObject
{
	Q_OBJECT

public:
	CWebSocketClient(QUrl url, CData  *m_Data, QObject *parent = 0);
	~CWebSocketClient();



signals:
	void closed();

private slots:
	void onConnected();
	void onTextMessageReceived(QString message);
	void onBinaryMessageReceived(QByteArray message);

private:
	QWebSocket			m_webSocket;
	QUrl				m_url;
	
	CData				*m_Data;
};

#endif // WEBSOCKETCLIENT_H
