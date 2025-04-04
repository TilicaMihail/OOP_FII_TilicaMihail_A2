#include "Mercedes.h"

double Mercedes::GetFuelCapacity() const { return 70; }
double Mercedes::GetFuelConsumption() const { return 8; }
double Mercedes::GetAverageSpeed(Weather weather) const {
    if (weather == Weather::Rain) return 75;
    if (weather == Weather::Sunny) return 110;
    return 65;
}
const char* Mercedes::GetName() const { return "Mercedes"; }
