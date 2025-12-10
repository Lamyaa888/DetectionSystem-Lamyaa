#ifndef LOGOBSERVER_H_INCLUDED
#define LOGOBSERVER_H_INCLUDED

#include <iostream>
#include "Observer.h"

class LogObserver : public Observer {
public:
    void update(const std::string& msg) override {
        std::cout << "[LOGGER] Log saved: " << msg << "\n";
    }
};

#endif // LOGOBSERVER_H_INCLUDED
