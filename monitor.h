#pragma once

int vitalsOk(float temperature, float pulseRate, float spo2);
int checkVitals(float temperature, float pulseRate, float spo2); // pure function
void showAlert(const char* message); // I/O function
