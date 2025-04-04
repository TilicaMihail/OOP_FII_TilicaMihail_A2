#include "Ford.h"

double Ford::GetFuelCapacity() const { return 60; }
double Ford::GetFuelConsumption() const { return 7; }
double Ford::GetAverageSpeed(Weather weather) const {
    if (weather == Weather::Rain) return 70;
    if (weather == Weather::Sunny) return 100;
    return 60;
}
const char* Ford::GetName() const { return "Ford"; }
