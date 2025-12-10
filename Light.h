#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

#include <iostream>
#include <windows.h>
#include "Observer.h"

class Light : public Observer {
public:
    void update(const std::string& msg) override {
        std::cout << "[LIGHT] Blinking... Danger detected!\n";
        Sleep(1000); // 1 second
    }
};

#endif // LIGHT_H_INCLUDED
