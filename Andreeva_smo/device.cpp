#include <math.h>
#include <algorithm>
#include <QApplication>

#include "device.h"

Andreeva_smo::Device::Device() {

    this->size = 0;
    this->alpha = 0;
    this->betta = 0;
}

Andreeva_smo::Device::Device(int size, float alpha, float betta) {

    this->size = size;
    this->alpha = alpha;
    this->betta = betta;
    for (int i = 0; i < size; i++) {
        devices.push_back(nullptr);
    }
}

bool Andreeva_smo::Device::isFreeDevice() {

    bool res = false;
    for (int i = 0; i < devices.size(); i++) {
        if (devices.at(i) == nullptr)
            res = true;
    }
    return res;
}

int Andreeva_smo::Device::addNewReq(float currentTime, Andreeva_smo::Request req) {

    float workTime = currentTime + ((float)qrand()/(float)RAND_MAX)*(betta - alpha) + alpha; // равномерный закон распределения

    for (int i = 0; i < devices.size(); i++) {
        if (devices.at(i) == nullptr) {
            devices.at(i) = new std::pair<float, Request>(workTime, Request(req.getWaitTime(),
                                                                            req.getSourceNum(),
                                                                            req.getRequestNum()));
            return i + 1;
        }
    }
    return -1;
}

std::list<std::pair<Andreeva_smo::Request, int>> Andreeva_smo::Device::readyDevices(float currentTime) {

    std::list<std::pair<Request, int>> tmpList;
    std::vector<std::pair<float, Request> *> tmpDev;

    for (int i = 0; i < devices.size(); i++) {
        if (devices.at(i) != nullptr) {
            if ((*devices.at(i)).first < currentTime) {
                tmpList.push_back(std::make_pair(Request((*devices.at(i)).first,
                                                         (*devices.at(i)).second.getSourceNum(),
                                                         (*devices.at(i)).second.getRequestNum()), i + 1));
                tmpDev.push_back(nullptr);
            } else
                tmpDev.push_back(devices.at(i));
        } else
            tmpDev.push_back(nullptr);
    }
    devices = tmpDev;
    return tmpList;
}
