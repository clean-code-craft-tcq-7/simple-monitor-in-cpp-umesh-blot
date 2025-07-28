#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Pure function: checks vitals and returns a code
// 0 = not ok, 1 = ok, 2 = temp critical, 3 = pulse out of range, 4 = spo2 out of range
int checkVitals(float temperature, float pulseRate, float spo2) {
  if (temperature > 102 || temperature < 95) {
    return 2;
  } else if (pulseRate < 60 || pulseRate > 100) {
    return 3;
  } else if (spo2 < 90) {
    return 4;
  }
  return 1;
}

// Handles the alert animation and message
void showAlert(const char* message) {
  cout << message << "\n";
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

// Main function: separates logic from I/O
int vitalsOk(float temperature, float pulseRate, float spo2) {
  int result = checkVitals(temperature, pulseRate, spo2);
  switch(result) {
    case 2:
      showAlert("Temperature is critical!");
      return 0;
    case 3:
      showAlert("Pulse Rate is out of range!");
      return 0;
    case 4:
      showAlert("Oxygen Saturation out of range!");
      return 0;
    default:
      return 1;
  }
}
