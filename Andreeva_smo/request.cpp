#include "request.h"

Andreeva_smo::Request::Request() {

    this->waitTime = 0.0;
    this->sourceNum = 0;
    this->requestNum = 0;
}

Andreeva_smo::Request::Request(float waitTime, int sourceNum, int requestNum) {

    this->waitTime = waitTime;
    this->sourceNum = sourceNum;
    this->requestNum = requestNum;
}

float Andreeva_smo::Request::getWaitTime() const { return waitTime; }

int Andreeva_smo::Request::getSourceNum() const { return sourceNum; }

int Andreeva_smo::Request::getRequestNum() const { return requestNum; }

void Andreeva_smo::Request::setWaitTime(float value) { waitTime = value; }
