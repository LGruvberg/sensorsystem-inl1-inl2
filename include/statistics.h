#pragma once
#include "measurement.h"
#include <vector>

namespace statistics {

    Measurement getMin(const std::vector<Measurement>& data);
    Measurement getMax(const std::vector<Measurement>& data);

    double getMean(const std::vector<Measurement>& data);
    double getStdDev(const std::vector<Measurement>& data);
}