#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <list>
#include <string>

#include "interpreter.h"

namespace Andreeva_smo {
class Controller {
public:

    Controller();
    std::list<std::string> work(Interpreter &interpreter);

    void setAlpha(float value);
    void setBetta(float value);
    void setLambda(float value);
    void setSourcesAmount(int value);
    void setBuffersAmount(int value);
    void setDevicesAmount(int value);
    void setRequestsNumber(int value);

private:

    float alpha, betta, lambda;
    int sourcesAmount, buffersAmount, devicesAmount, requestsNumber;

    };
}

#endif
