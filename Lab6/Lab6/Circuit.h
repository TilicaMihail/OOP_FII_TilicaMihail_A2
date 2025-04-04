#pragma once

#include "Car.h"
#include "Weather.h"

class Circuit {
private:
    double length;
    Weather weather;
    Car* cars[100];  // Array of pointers to cars (fixed size, 100 cars max)
    double results[100];  // Array of race results (time)
    Car* carResults[100];  // Array of car pointers for sorted results
    int carCount;

public:
    Circuit();
    ~Circuit();
    void SetLength(double len);
    void SetWeather(Weather w);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;
};


