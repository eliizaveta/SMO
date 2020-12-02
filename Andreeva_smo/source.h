#ifndef SOURCE_H
#define SOURCE_H

#include <cmath>

#include "request.h"

namespace Andreeva_smo {
class Source {
public:

    Source();
    Source(float lambda, int amountOfSources);

    Andreeva_smo::Request getNextReq();

private:

    float lambda, *waitTime;
    int amountOfSources, *requestNums;

    };
}

#endif
