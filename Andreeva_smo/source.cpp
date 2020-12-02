#include <QApplication>

#include "source.h"

Andreeva_smo::Source::Source() {

    this->lambda = 0;
    this->amountOfSources = 0;

    this->waitTime = new float[this->amountOfSources];
    this->requestNums = new int[this->amountOfSources];
}

Andreeva_smo::Source::Source(float lambda, int amountOfSources) {

    this->lambda = lambda;
    this->amountOfSources = amountOfSources;

    this->waitTime = new float[amountOfSources];
    this->requestNums = new int[amountOfSources];

    for (int i = 0; i < amountOfSources; i++) {
        this->requestNums[i] = 0;
        this->waitTime[i] = -1;
    }
}

Andreeva_smo::Request Andreeva_smo::Source::getNextReq() {

    for (int i = 0; i < amountOfSources; i++) {
        if (waitTime[i] <= 0) {
            requestNums[i]++;
            waitTime[i] = (-1/lambda)*std::log(((float)qrand()/(float)RAND_MAX)); //пуассоновский поток
        }
    }

    std::pair<int, float> min = std::make_pair(0, waitTime[0]);
    for (int i = 0; i < amountOfSources; i++) {
        if (waitTime[i] < min.second) {
            min = std::make_pair(i, waitTime[i]);
        }
    }

    for (int i = 0; i < amountOfSources; i++) {
        waitTime[i] -= min.second;
    }

    return Request(min.second, min.first + 1, requestNums[min.first]);
}




