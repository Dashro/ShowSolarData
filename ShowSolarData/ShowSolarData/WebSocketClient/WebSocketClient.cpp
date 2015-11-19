#include "WebSocketClient.h"
#include "qjsondocument.h"

CWebSocketClient::CWebSocketClient(QUrl url, QObject *parent)
	: m_url(url), QObject(parent)
{
	//m_url = QUrl(QStringLiteral("ws://localhost:1234"));

	connect(&m_webSocket, &QWebSocket::connected,		this, &CWebSocketClient::onConnected);
	connect(&m_webSocket, &QWebSocket::disconnected,	this, &CWebSocketClient::serverDisconnected);

	//Client tries to connect every 5s
	connection_Timer = new QTimer(this);
	connection_Timer->setInterval(5000);

	connect(connection_Timer, SIGNAL(timeout()), this, SLOT(onConnectionTimeout()));

	connect(&m_webSocket, SIGNAL(connected()),		connection_Timer, SLOT(stop()));
	connect(&m_webSocket, SIGNAL(disconnected()),	connection_Timer, SLOT(start()));

	connection_Timer->start();
}

CWebSocketClient::~CWebSocketClient()
{

}

void CWebSocketClient::connectToServer(QUrl url)
{
	m_webSocket.abort();
	m_url = url;
	qDebug() << "Connected to Websocket Server" << m_url;

	m_webSocket.open(QUrl(m_url));

}


void CWebSocketClient::onConnected()
{

	qDebug() << "WebSocket connected";
	connect(&m_webSocket, &QWebSocket::textMessageReceived,
		this, &CWebSocketClient::onTextMessageReceived);
	connect(&m_webSocket, &QWebSocket::binaryMessageReceived,
		this, &CWebSocketClient::onBinaryMessageReceived);
	m_webSocket.sendTextMessage(QStringLiteral("3"));

	emit serverConnected(m_url.toString());
}

void CWebSocketClient::onBinaryMessageReceived(QByteArray message)
{
	QJsonDocument json_doc = QJsonDocument::fromBinaryData(message);

	if (json_doc.isNull())
	{
		qWarning() << "recieved unvalid json-Script";
		return;
	}

	QJsonObject json = json_doc.object();

	qDebug() << "Json Script received: " << json["Name"].toString();

	if (json["Name"].toString() == "Initial-Skript")
		emit recievedInitialScript(json);

	else if (json["Name"].toString() == "Data-Skript")
		emit recievedDataScript(json);
	
	return;

	//if (json["Name"].toString() == "Initial-Skript")
	//{
	//	m_Data->clear();
	//	QStringList buffer;
	//	buffer << "TimeStamp" << "Einspeisung" << "Bezug" << "ETotal";
	//	m_Data->setHeader(buffer);
	//	buffer.clear();
	//	buffer << json["TimeStamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << json["ETotal"].toString();
	//	m_Data->setUnits(buffer);
	//}
	//else if (json["Name"].toString() == "Data-Skript")
	//{
	//	QStringList buffer;
	//	buffer << json["TimeStamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << json["ETotal"].toString();
	//	m_Data->setRow(buffer);
	//}


}


void CWebSocketClient::onTextMessageReceived(QString message)
{
	QJsonParseError error;
	QJsonDocument json_doc = QJsonDocument::fromJson(message.toUtf8(), &error);

	if (json_doc.isNull())
	{
		qWarning() << "recieved unvalid json-Script: " << error.errorString();
		return;
	}

	QJsonObject json = json_doc.object();

	qDebug() << "Json Script received:" << json["Name"].toString();

	if (json["Name"].toString() == "Initial-Skript")
		emit recievedInitialScript(json);

	else if (json["Name"].toString() == "Data-Skript")
		emit recievedDataScript(json);

	return;


	/*qDebug() << "Text Message received:" << message;
	QStringList buffer;

	QJsonObject json = QJsonDocument::fromJson(message.toUtf8()).object();
	qDebug() << "Json Script received:" << json["Name"].toString();

	if (json["Name"].toString() == "Initial-Skript")
	{
		m_Data->clear();

		buffer << "TimeStamp" << "Einspeisung" << "Bezug" << "ETotal";
		m_Data->setHeader(buffer);
		buffer.clear();
		buffer << json["TimeStamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << json["ETotal"].toString();
		m_Data->setUnits(buffer);
	}
	else if (json["Name"].toString() == "Data-Skript")
	{
		buffer << json["TimeStamp"].toString() << json["Einspeisung"].toString() << json["Bezug"].toString() << json["ETotal"].toString();
		m_Data->setRow(buffer);
	}*/
}

void CWebSocketClient::onConnectionTimeout()
{
	qDebug() << "Try to connect to:" << m_url;
	m_webSocket.open(QUrl(m_url));

}