#pragma once
void handleNotFound() {
	String message = "File Not Found\n\n";
	message += "URI: ";
	message += server.uri();
	message += "\nMethod: ";
	message += (server.method() == HTTP_GET) ? "GET" : "POST";
	message += "\nArguments: ";
	message += server.args();
	message += "\n";
	for (uint8_t i = 0; i < server.args(); i++) {
		message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
	}
	server.send(404, "text/plain", message);
}

void handleMinimalUpload() {
	char temp[1500];
	int sec = millis() / 1000;
	int min = sec / 60;
	int hr = min / 60;

	snprintf(temp, 1500,
		"<!DOCTYPE html>\
        <html>\
          <head>\
            <title>ESP8266 Upload</title>\
            <meta charset=\"utf-8\">\
            <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\
            <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
          </head>\
          <body>\
            <form action=\"/edit\" method=\"post\" enctype=\"multipart/form-data\">\
              <input type=\"file\" name=\"data\">\
              <input type=\"text\" name=\"path\" value=\"/\">\
              <button>Upload</button>\
            </form>\
          </body>\
        </html>",
		hr, min % 60, sec % 60
	);
	server.send(200, "text/html", temp);
}








