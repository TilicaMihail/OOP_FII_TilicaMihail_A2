#include "Mazda.h"

double Mazda::GetFuelCapacity() const { return 58; }
double Mazda::GetFuelConsumption() const { return 6.5; }
double Mazda::GetAverageSpeed(Weather weather) const {
    if (weather == Weather::Rain) return 68;
    if (weather == Weather::Sunny) return 98;
    return 58;
}
const char* Mazda::GetName() const { return "Mazda"; }
