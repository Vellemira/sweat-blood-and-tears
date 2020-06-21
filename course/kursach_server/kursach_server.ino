// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       kursach_server.ino
    Created:	22.04.2020 17:05:48
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//
//#define WEBSOCKETS_NETWORK_TYPE NETWORK_ESP8266_ASYNC
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <WiFiClient.h>
#include <FS.h>
#include <WiFiManager.h>
#include <Ticker.h>
#include <WebSockets.h>           
#include <WebSocketsServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include "FastLED.h"

#define PIN 2
#define NUM_LEDS 28
CRGB leds[NUM_LEDS];
byte counter;
int sensorValue = 0;

ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);
ESP8266HTTPUpdateServer httpUpdater;
Ticker serevmaintain;
int brightness = 0;
int speed = 0;
int step = 0;
bool button = 0;
void configModeCallback(WiFiManager *myWiFiManager) {

}
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght);
#include "spiffs_webserver.h"
#include "handlers.h"
const char* www_username = "admin";
const char* www_password = "esp8266";
// allows you to set the realm of authentication Default:"Login Required"
const char* www_realm = "Custom Auth Realm";
// the Content of the HTML response in case of Unautherized Access Default:empty
String authFailResponse = "Authentication Failed";

// The setup() function runs once each time the micro-controller starts
void setup()
{


	//motor led
	pinMode(D8, OUTPUT);
	pinMode(D7, OUTPUT);
	FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	pinMode(2, OUTPUT);
	FastLED.setBrightness(10);
	// motor led


	WiFiManager wifiManager;
	//reset settings - for testing
	//wifiManager.resetSettings();

	//set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
	wifiManager.setAPCallback(configModeCallback);

	if (!wifiManager.autoConnect()) {
		ESP.reset();
		delay(10000);
	}
	SPIFFS.begin();
	{
		Dir dir = SPIFFS.openDir("/");
		while (dir.next()) {
			String fileName = dir.fileName();
			size_t fileSize = dir.fileSize();
			// DBG_OUTPUT_PORT.printf("FS File: %s, size: %s\n", fileName.c_str(), formatBytes(fileSize).c_str());
		}

	}
	//server.getServer().setServerKeyAndCert_P(rsakey, sizeof(rsakey), x509, sizeof(x509));
	httpUpdater.setup(&server);
	webSocket.begin();
	webSocket.onEvent(webSocketEvent);
	
	server.on("/", []() {
		if (!server.authenticate(www_username, www_password))
			//Basic Auth Method with Custom realm and Failure Response
			//return server.requestAuthentication(BASIC_AUTH, www_realm, authFailResponse);
			//Digest Auth Method with realm="Login Required" and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH);
			//Digest Auth Method with Custom realm and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH, www_realm);
			//Digest Auth Method with Custom realm and Failure Response
		{
			return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
		}
		handleFileRead("/index.htm");
		
	});
	//server.on("/list", HTTP_GET, handleFileList);
	//load editor
	server.on("/edit", HTTP_GET, []() {
		if (!server.authenticate(www_username, www_password))
			//Basic Auth Method with Custom realm and Failure Response
			//return server.requestAuthentication(BASIC_AUTH, www_realm, authFailResponse);
			//Digest Auth Method with realm="Login Required" and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH);
			//Digest Auth Method with Custom realm and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH, www_realm);
			//Digest Auth Method with Custom realm and Failure Response
		{
			return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
		}
		if (!handleFileRead("/edit.htm")) server.send(404, "text/plain", "FileNotFound");
	});
	//create file
	server.on("/edit", HTTP_PUT, []() {
		if (!server.authenticate(www_username, www_password))
			//Basic Auth Method with Custom realm and Failure Response
			//return server.requestAuthentication(BASIC_AUTH, www_realm, authFailResponse);
			//Digest Auth Method with realm="Login Required" and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH);
			//Digest Auth Method with Custom realm and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH, www_realm);
			//Digest Auth Method with Custom realm and Failure Response
		{
			return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
		}
		handleFileCreate();
	});
	server.on("/edit", HTTP_DELETE, []() {
		if (!server.authenticate(www_username, www_password))
			//Basic Auth Method with Custom realm and Failure Response
			//return server.requestAuthentication(BASIC_AUTH, www_realm, authFailResponse);
			//Digest Auth Method with realm="Login Required" and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH);
			//Digest Auth Method with Custom realm and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH, www_realm);
			//Digest Auth Method with Custom realm and Failure Response
		{
			return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
		}
		handleFileDelete();
	});

	//delete file
	server.on("/edit", HTTP_POST, []() {
		if (!server.authenticate(www_username, www_password))
			//Basic Auth Method with Custom realm and Failure Response
			//return server.requestAuthentication(BASIC_AUTH, www_realm, authFailResponse);
			//Digest Auth Method with realm="Login Required" and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH);
			//Digest Auth Method with Custom realm and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH, www_realm);
			//Digest Auth Method with Custom realm and Failure Response
		{
			return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
		}
		server.send(200, "text/plain", "");
	},handleFileUpload);
	//first callback is called after the request has ended with all parsed arguments
	//second callback handles file uploads at that location
	server.on("/list",  []() {
		if (!server.authenticate(www_username, www_password))
			//Basic Auth Method with Custom realm and Failure Response
			//return server.requestAuthentication(BASIC_AUTH, www_realm, authFailResponse);
			//Digest Auth Method with realm="Login Required" and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH);
			//Digest Auth Method with Custom realm and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH, www_realm);
			//Digest Auth Method with Custom realm and Failure Response
		{
			return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
		}
		handleFileList();
	});
	//get heap status, analog input value and all GPIO statuses in one json call
	//server.on("/esp_status", HTTP_GET, []() {
	//	String json = "{";
	//	json += "\"heap\":" + String(ESP.getFreeHeap());
	//	json += ", \"analog\":" + String(analogRead(A0));
	//	json += ", \"gpio\":" + String((uint32_t)(((GPI | GPO) & 0xFFFF) | ((GP16I & 0x01) << 16)));
	//	json += "}";
	//	server.send(200, "text/json", json);
	//	json = String();
	//});


	//called when the url is not defined here
	//use it to load content from SPIFFS
	server.onNotFound([]() {
		if (!handleFileRead(server.uri()))
			handleNotFound();
	});

	//server.on("/upload", handleMinimalUpload);
	server.on("/upload",  []() {
		if (!server.authenticate(www_username, www_password))
			//Basic Auth Method with Custom realm and Failure Response
			//return server.requestAuthentication(BASIC_AUTH, www_realm, authFailResponse);
			//Digest Auth Method with realm="Login Required" and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH);
			//Digest Auth Method with Custom realm and empty Failure Response
			//return server.requestAuthentication(DIGEST_AUTH, www_realm);
			//Digest Auth Method with Custom realm and Failure Response
		{
			return server.requestAuthentication(DIGEST_AUTH, www_realm, authFailResponse);
		}
		handleMinimalUpload();
	});
	//server.on("/restart", []() {

	//	server.send(200, "text/plain", "restarting...");
	//	ESP.restart();
	//});

	//server.on("/reset_wlan", []() {
	//	server.send(200, "text/plain", "Resetting WLAN and restarting...");
	//	WiFiManager wifiManager;
	//	wifiManager.resetSettings();
	//	ESP.restart();
	//});
	server.begin(80);
	serevmaintain.attach_ms(10, websockmaintain);
	
}
void websockmaintain() {
	webSocket.loop();
}
// Add the main program code into the continuous loop() function
void loop()
{
digitalWrite(D8, button);
FastLED.setBrightness(brightness);
rainbow();
}
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) {
	switch (type) {
	case WStype_DISCONNECTED:
		// DBG_OUTPUT_PORT.printf("WS: [%u] Disconnected!\n", num);
		break;

	case WStype_CONNECTED: {
		IPAddress ip = webSocket.remoteIP(num);
		// DBG_OUTPUT_PORT.printf("WS: [%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

				//    DBG_OUTPUT_PORT.printf("Get status info.");

		String json = "@";
	
		json += brightness;
		webSocket.sendTXT(num, json);
		json = "#";
		json += speed;
		webSocket.sendTXT(num, json);
		json = "*";
		json += step;
		webSocket.sendTXT(num, json);

		if (button) {

			json = "?1";

		}
		else json = "?0";
		webSocket.sendTXT(num, json);
	}
						   break;

	case WStype_TEXT:
		// DBG_OUTPUT_PORT.printf("WS: [%u] get Text: %s\n", num, payload);

		 // # ==> Set main color
		

		// # ==> Set delay
		if (payload[0] == '?') {
			// decode delay data
			button = !button;
			String json;

			if (button) {

				json = "?1";

			}
			else json = "?0";
			webSocket.broadcastTXT( json);
		
		}

		// ! ==> Activate mode
		if (payload[0] == '@') {
			// we get mode data
			brightness = String((char *)&payload[1]).toInt();

			String json = "@";

			json += brightness;
			// DBG_OUTPUT_PORT.println(json);
			webSocket.broadcastTXT( json);


		}

		if (payload[0] == '#') {
			speed = String((char *)&payload[1]).toInt();
			String json = "#";
			json += speed;
			webSocket.broadcastTXT(json);
		}
		if (payload[0] == '*') {
			// we get mode data
			step = String((char *)&payload[1]).toInt();

			String json = "*";

			json += step;
			// DBG_OUTPUT_PORT.println(json);
			webSocket.broadcastTXT(json);


		}
		// $ ==> Get status Info.

		break;
	}
}

void checkForRequests() {
	webSocket.loop();
	server.handleClient();
}

void rainbow()
{
	for (int i = 0; i < NUM_LEDS; i++) {       
	 
		leds[i] = CHSV(counter + i * step, 255, 255);
	}
	counter++;       
	FastLED.show();
	checkForRequests();
	delay(speed);        
}
