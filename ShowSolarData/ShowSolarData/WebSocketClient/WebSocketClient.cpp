#include "WebSocketClient.h"
#include "qjsondocument.h"

CWebSocketClient::CWebSocketClient(QUrl url, CData  *m_Data, QObject *parent)
	: m_url(url), m_Data(m_Data), QObject(parent)
{
	//m_url = QUrl(QStringLiteral("ws://localhost:1234"));

	qDebug() << "WebSocket server:" << m_url;
	connect(&m_webSocket, &QWebSocket::connected, this, &CWebSocketClient::onConnected);
	connect(&m_webSocket, &QWebSocket::disconnected, this, &CWebSocketClient::serverDisconnected);

	m_webSocket.open(QUrl(m_url));
}

CWebSocketClient::~CWebSocketClient()
{

}

void CWebSocketClient::connectToServer(QUrl url)
{
	m_url = url;
	qDebug() << "WebSocket server:" << m_url;

	m_webSocket.open(QUrl(m_url));

}


void CWebSocketClient::onConnected()
{

	qDebug() << "WebSocket connected";
	connect(&m_webSocket, &QWebSocket::textMessageReceived,
		this, &CWebSocketClient::onTextMessageReceived);
	connect(&m_webSocket, &QWebSocket::binaryMessageReceived,
		this, &CWebSocketClient::onBinaryMessageReceived);

	emit serverConnected(m_url.toString());
}

void CWebSocketClient::onBinaryMessageReceived(QByteArray message)
{
	QJsonObject json = QJsonDocument::fromBinaryData(message).object();
	qDebug() << "Json Script received:" << json["Name"].toString();

	if (json["Name"].toString() == "Initial-Skript")
	{
		m_Data->clear();
		QStringList buffer;
		buffer << "TimeStamp" << "Einspeisung" << "Bezug" << "ETotal";
		m_Data->setHeader(buffer);
		buffer.clear();
		buffer << json["TimeStamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << json["ETotal"].toString();
		m_Data->setUnits(buffer);
	}
	else if (json["Name"].toString() == "Data-Skript")
	{
		QStringList buffer;
		buffer << json["TimeStamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << json["ETotal"].toString();
		m_Data->setRow(buffer);
	}


}


void CWebSocketClient::onTextMessageReceived(QString message)
{
	qDebug() << "Text Message received:" << message;
}