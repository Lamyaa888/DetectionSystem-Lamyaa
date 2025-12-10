#ifndef OBSERVER_H_INCLUDED
#define OBSERVER_H_INCLUDED

#include <string>

class Observer {
public:
    virtual void update(const std::string& msg) = 0;
    virtual ~Observer() {}
};

#endif // OBSERVER_H_INCLUDED
