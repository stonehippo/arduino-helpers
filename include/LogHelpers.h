/*
Copyright (C) 2015 George White <stonehippo@gmail.com> All rights reserved.

See https://raw.githubusercontent.com/stonehippo/arduino-helpers/master/LICENSE.txt for license details. All rights reserved.
*/

// ******************* Logging and debug helpers ******************* 
#define DEBUG true

void logMessage(String message) {
  if (DEBUG) {
    Serial.println(message);
  } 
}

void note(String message) {
  String fullMessage = "NOTE: "+ message;
  logMessage(fullMessage); 
}

void info(String message) {
  String fullMessage = "INFO: "+ message;
  logMessage(fullMessage); 
}

void warn(String message) {
  String fullMessage = "WARN: "+ message;
  logMessage(fullMessage); 
}

void startLog() {
  if (DEBUG) {
    Serial.begin(9600);
    note("Now logging to serial");
  }
}
