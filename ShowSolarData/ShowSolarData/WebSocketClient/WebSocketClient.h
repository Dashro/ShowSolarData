#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H
#include <QtWebSockets/QWebSocket>
#include <QObject>

class CWebSocketClient : public QObject
{
	Q_OBJECT

public:
	CWebSocketClient(QObject *parent);
	~CWebSocketClient();

signals:
	void closed();

private slots:
	void onConnected();
	void onTextMessageReceived(QString message);

private:
	QWebSocket	m_webSocket;
	QUrl		m_url;
	
};

#endif // WEBSOCKETCLIENT_H
