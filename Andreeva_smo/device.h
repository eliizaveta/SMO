#ifndef DEVICE_H
#define DEVICE_H

#include <list>
#include <vector>
#include <utility>

#include "request.h"

namespace Andreeva_smo {
class Device {
public:

    Device();
    Device(int size, float alpha, float beta);

    bool isFreeDevice();
    int addNewReq(float currentTime, Request request);
    std::list<std::pair<Request, int>> readyDevices(float currentTime);

private:

    int size;
    float alpha, betta;
    std::vector<std::pair<float, Request> *> devices; //для пошагового

    };
}

#endif
