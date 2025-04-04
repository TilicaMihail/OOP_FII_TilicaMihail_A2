#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
#include <cstdio>  // For printf

Circuit::Circuit() : length(0), weather(Weather::Sunny), carCount(0) {}

Circuit::~Circuit() {
    for (int i = 0; i < carCount; ++i) {
        delete cars[i];  // Clean up dynamic memory
    }
}

void Circuit::SetLength(double len) {
    length = len;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
}

void Circuit::AddCar(Car* car) {
    if (carCount < 100) {
        cars[carCount++] = car;
    }
}

void Circuit::Race() {
    for (int i = 0; i < carCount; ++i) {
        double maxDistance = cars[i]->GetFuelCapacity() / cars[i]->GetFuelConsumption() * 100;
        if (maxDistance >= length) {
            double time = length / cars[i]->GetAverageSpeed(weather);
            results[i] = time;
            carResults[i] = cars[i];
        }
        else {
            results[i] = -1;  // Indicates car didn't finish
            carResults[i] = nullptr;
        }
    }

    // Simple bubble sort for results
    for (int i = 0; i < carCount - 1; ++i) {
        for (int j = 0; j < carCount - i - 1; ++j) {
            if (results[j] > results[j + 1] && results[j + 1] != -1) {
                double tempResult = results[j];
                Car* tempCar = carResults[j];
                results[j] = results[j + 1];
                carResults[j] = carResults[j + 1];
                results[j + 1] = tempResult;
                carResults[j + 1] = tempCar;
            }
        }
    }
}

void Circuit::ShowFinalRanks() const {
    for (int i = 0; i < carCount; ++i) {
        if (carResults[i] != nullptr) {
            // Use printf instead of std::cout
            printf("%s finished in %.2f hours\n", carResults[i]->GetName(), results[i]);
        }
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    for (int i = 0; i < carCount; ++i) {
        if (results[i] == -1) {
            // Use printf instead of std::cout
            printf("%s did not finish the race\n", cars[i]->GetName());
        }
    }
}
