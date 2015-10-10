#include "WebSocketClient.h"

CWebSocketClient::CWebSocketClient(QObject *parent)
	: QObject(parent)
{
	m_url = QUrl(QStringLiteral("ws://localhost:1234"));

	qDebug() << "WebSocket server:" << m_url;
	connect(&m_webSocket, &QWebSocket::connected, this, &CWebSocketClient::onConnected);
	connect(&m_webSocket, &QWebSocket::disconnected, this, &CWebSocketClient::closed);
	m_webSocket.open(QUrl(m_url));
}

CWebSocketClient::~CWebSocketClient()
{

}


void CWebSocketClient::onConnected()
{

	qDebug() << "WebSocket connected";
	connect(&m_webSocket, &QWebSocket::textMessageReceived,
		this, &CWebSocketClient::onTextMessageReceived);
	m_webSocket.sendTextMessage(QStringLiteral("Hello, world!"));
}

void CWebSocketClient::onTextMessageReceived(QString message)
{
	qDebug() << "Message received:" << message;
}