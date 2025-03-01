/*
Copyright (C) 2015-2022 George White <stonehippo@gmail.com>, All rights reserved.

See https://raw.githubusercontent.com/stonehippo/arduino-helpers/master/LICENSE.txt for license details. 
*/

// ******************* Timing helpers ******************* 
void startTimer(long &timer) {
  timer = millis(); 
}

void timerAdd(long &timer, long add) {
  timer = timer + add;
}

boolean timerLess(long &timer1, long &timer2) {
  if (timer1 < timer2) {
    return true;
  }
  return false;
}

long timerDiff(long &timer1, long &timer2) {
  return timer1 - timer2;
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
