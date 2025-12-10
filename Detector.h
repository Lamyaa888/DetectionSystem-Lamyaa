#ifndef DETECTOR_H_INCLUDED
#define DETECTOR_H_INCLUDED

#include <vector>
#include <string>
#include "Observer.h"

class Detector {
private:

    // Updated: reorganized observer list handling for clarity
    // list of all observers (alarm, light, logger)

    std::vector<Observer*> observers;
    bool dangerDetected = false;

public:
    void attach(Observer* obs) {
        observers.push_back(obs);
    }

    void setDanger(bool state) {
        dangerDetected = state;
        notify("Danger!");
    }

    void notify(const std::string& msg) {
        for (auto obs : observers) {
            obs->update(msg);
        }
    }
};

#endif // DETECTOR_H_INCLUDED

//  reorganized observer list handling for clarity
