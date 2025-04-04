#include "Dacia.h"

double Dacia::GetFuelCapacity() const { return 50; }
double Dacia::GetFuelConsumption() const { return 5; }
double Dacia::GetAverageSpeed(Weather weather) const {
    if (weather == Weather::Rain) return 60;
    if (weather == Weather::Sunny) return 90;
    return 50;
}
const char* Dacia::GetName() const { return "Dacia"; }