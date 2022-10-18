/*
Copyright (C) 2015-2022 George White <stonehippo@gmail.com>, All rights reserved.

See https://raw.githubusercontent.com/stonehippo/arduino-helpers/master/LICENSE.txt for license details. 
*/

// ******************* Timing helpers ******************* 
void startTimer(long &timer) {
  timer = millis(); 
}

boolean isTimerExpired(long &timer, long expiration) {
  long current = millis() - timer;
  return current > expiration;
}

boolean isTimerRunning(long &timer) {
  return !timer == 0;
}

void clearTimer(long &timer) {
  timer = 0; 
}
