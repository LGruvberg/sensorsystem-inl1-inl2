#include "../include/statistics.h";
#include <numeric>
#include <cmath>
#include <algorithm>

namespace statistics {
    Measurement getMin(const std::vector<Measurement>& data) {
    // Find measurement with smallest value
    return *std::min_element(data.begin(), data.end(),
        [](const Measurement& a, const Measurement& b) {
            return a.value < b.value; });
}

Measurement getMax(const std::vector<Measurement>& data) {
    // Find measurement with smallest value
    return *std::max_element(data.begin(), data.end(),
        [](const Measurement& a, const Measurement& b) {
            return a.value < b.value; 
        }
    );
}

double getMean(const std::vector<Measurement>& data) {
    //  Sum all values, fivide by count
    double sum = std:: accumulate(
        data.begin(), data.end(),
        0.0,
        [](double acc, const Measurement& m) {
            return acc + m.value;
        }
    );
    return sum / data.size();
}

double stdDev(const std::vector<Measurement>& data) {
    double mean = getMean(data);
    double variance = 0.0;

    for (const auto& m : data) {
        variance += std::pow(m.value - mean, 2);
    }
    variance /= (data.size() - 1);  // sample stdDev

    return std::sqrt(variance);
}
}