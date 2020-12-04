#include "buffer.h"

Andreeva_smo::Buffer::Buffer() {

    this->size = 0;
}

Andreeva_smo::Buffer::Buffer(int size) {

    this->size = size;
    for (int i = 0; i < size; i++) {
        buffers.push_back(nullptr);
    }
}

bool Andreeva_smo::Buffer::isFreeBuffer() {

    bool res = false;
    for (int i = 0; i < buffers.size(); i++) {
        if (buffers.at(i) == nullptr)
            res = true;
    }
    return res;
}

bool Andreeva_smo::Buffer::isEmptyBuffer() {

    bool res = true;
    for (int i = 0; i < buffers.size(); i++) {
        if (buffers.at(i) != nullptr)
            res = false;
    }
    return res;
}

int Andreeva_smo::Buffer::addNewReq(Andreeva_smo::Request req) {

    for (int i = 0; i < buffers.size(); i++) {

        if (cursor >= buffers.size() || cursor < 0) {
            cursor = 0;
        }

        if (buffers.at(cursor) == nullptr) {
            buffers.at(cursor) = new Request(req.getWaitTime(),
                                             req.getSourceNum(),
                                             req.getRequestNum());
            cursor++; //передвигаем на следующее место
            return cursor - 1;
        }
        cursor++;
    }
    return -1;
}

std::pair<Andreeva_smo::Request, int> Andreeva_smo::Buffer::deleteReq() {

    if (cursor >= buffers.size() || cursor < 0) {
        cursor = 0;
    }

    for (int i = 0; i < buffers.size(); i++) {
        if (i == cursor) {
            Request req = *buffers.at(i);
            buffers.at(i) = nullptr;
            return std::make_pair(req, i);
        }
    }
    return std::make_pair(Request(), -1);
}

std::pair<Andreeva_smo::Request, int> Andreeva_smo::Buffer::getReq() {

    std::size_t reqToGet = 0;
    bool selected = false;

    for (std::size_t i = 0; i < buffers.size(); i++) {

        if (buffers.at(i) != nullptr) {
            if (!selected) {
                reqToGet = i;
                selected = true;
            }

         //FIFO
         if (buffers.at(i)->getWaitTime() < buffers.at(reqToGet)->getWaitTime())
             reqToGet = i;

         else if (buffers.at(i)->getWaitTime() == buffers.at(reqToGet)->getWaitTime()) {
            if (buffers.at(i)->getSourceNum() < buffers.at(reqToGet)->getSourceNum()) {
                reqToGet = i;
                } else if (buffers.at(i)->getSourceNum() == buffers.at(reqToGet)->getSourceNum()) {
                    if (buffers.at(i)->getRequestNum() > buffers.at(reqToGet)->getRequestNum()) {
                        reqToGet = i;
                    }
                }
            }
        }

        if (!selected) {
            reqToGet = i;
        }
    }

    Request req = *buffers.at(reqToGet);
    buffers.at(reqToGet) = nullptr;
    if (selected)
        return std::make_pair(req, reqToGet);
    else
        return std::make_pair(Andreeva_smo::Request(), -1);
}

