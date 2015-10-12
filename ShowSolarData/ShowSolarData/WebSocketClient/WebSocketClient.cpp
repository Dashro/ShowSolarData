#include "WebSocketClient.h"
#include "qjsondocument.h"

CWebSocketClient::CWebSocketClient(QUrl url, CData  *m_Data, QObject *parent)
	: m_url(url), m_Data(m_Data), QObject(parent)
{
	//m_url = QUrl(QStringLiteral("ws://localhost:1234"));

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
	connect(&m_webSocket, &QWebSocket::binaryMessageReceived,
		this, &CWebSocketClient::onBinaryMessageReceived);
}

void CWebSocketClient::onBinaryMessageReceived(QByteArray message)
{
	qDebug() << "BinaryMessage received:" << message;

	QJsonObject json = QJsonDocument::fromBinaryData(message).object();
	qDebug() << "Json Script received:" << json["Name"].toString();

	if (json["Name"].toString() == "Initial-Skript")
	{
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
	qDebug() << "Message received:" << message;


	//if (message.startsWith("SOLAR"))
	//{
	//	message.remove("SOLAR");
	//	if (message.startsWith("UNITS"))
	//	{
	//		message.remove("UNITS");
	//		m_SolarData->prozessLine(message, 3);
	//	}
	//	else if (message.startsWith("HEADER"))
	//	{
	//		message.remove("HEADER");
	//		m_SolarData->prozessLine(message, 4);
	//	}
	//	else
	//	{
	//		m_SolarData->prozessLine(message, 5);
	//	}
	//}
	//if (message.startsWith("CONSUMPTION"))
	//{
	//	message.remove("CONSUMPTION");
	//	if (message.startsWith("UNITS"))
	//	{
	//		message.remove("UNITS");
	//		m_ConsumptionData->prozessLine(message, 3);
	//	}
	//	else if (message.startsWith("HEADER"))
	//	{
	//		message.remove("HEADER");
	//		m_ConsumptionData->prozessLine(message, 4);
	//	}
	//	else
	//	{
	//		m_ConsumptionData->prozessLine(message, 5);
	//	}
	//}
}