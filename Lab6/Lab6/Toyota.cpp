#include "Toyota.h"

double Toyota::GetFuelCapacity() const { return 55; }
double Toyota::GetFuelConsumption() const { return 6; }
double Toyota::GetAverageSpeed(Weather weather) const {
    if (weather == Weather::Rain) return 65;
    if (weather == Weather::Sunny) return 95;
    return 55;
}
const char* Toyota::GetName() const { return "Toyota"; }
