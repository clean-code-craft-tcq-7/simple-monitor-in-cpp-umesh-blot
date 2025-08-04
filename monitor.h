#pragma once
#include <assert.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

int vitalsOk(float temperature, float pulseRate, float spo2);
void displayVitalAlert(const std::string& message);
int isTemperatureOk(float temperature);
int isPulseRateOk(float pulseRate);
int isSpo2Ok(float spo2);
