# Arduino Helpers

Some code that I've found useful more than a few times when working with Arduinos.

This code is pretty easy to use. Each helper is a simple header file, defining a set of methods. Dependencies are kept to a minimum, relying on standard Arduion API elements.

## TimingHelpers.h

This include has some really basic tools for handling "is it time yet" queries to implement non-blocking delays and multitasking. I've also used these for debouncing.

It's not guaranteed execution, since it depends on both the accuracy of the `millis()` method and the execution speed of `loop()`, so it may be a few milliseconds longer than the expiration.

An arbitratry number of timers can be created, since each one is just a `long` value. They take up no CPU cycles unless they're being checked.

```c++
#include "TimingHelpers.h"

#define TIMER_INTERVAL

// create a timer
long timer = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    // if the timer has never started, or has been cleared, fire it up
    if (!isTimerRunning(timer)) {
        startTimer(timer);
    }

    // to see if about 5 seconds have passed
    if (isTimerExpired(timer, 5000)) {
        Serial.println("Ding!");
        // reset the timer; it will get started on the next pass
        clearTimer();
    }
}

```

| function | description |
|:--|:--|
| `void startTimer(long &timer)` | "starts" a timer; if called on a timer that is already running, it will restart it at the current time. |
| `boolean isTimerExpired(long &timer, long expiration)` | checks a timer against an expiration value in millisecond. If the timers meets or exceeds that value, returns true. |
| `boolean isTimerRunning(long &timer)` | checks to see if the timer is currently "running" (i.e. not set to zero). |
| `void clearTimer(long &timer)` | resets a timer to zero, effectively "stopping" it. |

## LogHelpers.h

This is a wrapper around Serial and `Serial.println()`. It provides control for basic debugging output, with functions to send various levels of message (NOTE, INFO, and WARN are defined).

```c++
#include "LogHelpers.h"

#define DEBUG true // change to false to disable Serial and LogHelper output

void setup() {
    startLog();
}

void loop() {
    // if something happens that you want to log to the console...
    note("Something happened that you should know about");
}
```

| function | description |
|:--|:--|
| `void startLog(String message)` | calls `Serial.begin(9600)` if DEGUG is `true` |
| `void info(String message)` | logs an INFO message |
| `void noteString message()` | logs an NOTE message |
| `warm(String message)` | logs an WARN message |
| `void logMessage(String message)` | generic logging method; all other logging methods delegate to this one |