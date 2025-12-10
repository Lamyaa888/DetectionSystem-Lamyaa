#ifndef ALARM_H_INCLUDED
#define ALARM_H_INCLUDED

#include <iostream>
#include "Observer.h"

class Alarm : public Observer {
public:
    void update(const std::string& msg) override {
        std::cout << "[ALARM] Danger detected! Alarm is ON!\n";
    }
};

#endif // ALARM_H_INCLUDED
