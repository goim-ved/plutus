#include "maliketh/core/statistics.hpp"
#include <cmath>
#include <stdexcept>

namespace maliketh {
namespace math {

Real mean(const std::vector<Real>& data) {
    if (data.empty()) {
        throw std::invalid_argument("mean requires non-empty data");
    }

    Real running_mean = 0.0;
    for (Size i = 0; i < data.size(); ++i) {
        running_mean += (data[i] - running_mean) / static_cast<Real>(i + 1);
    }
    return running_mean;
}

Real variance(const std::vector<Real>& data) {
    if (data.size() < 2) {
        throw std::invalid_argument("variance requires at least two data points");
    }

    Real running_mean = 0.0;
    Real sum_of_squared_diffs = 0.0;

    for (Size i = 0; i < data.size(); ++i) {
        Real delta = data[i] - running_mean;
        running_mean += delta / static_cast<Real>(i + 1);
        Real delta2 = data[i] - running_mean;
        sum_of_squared_diffs += delta * delta2;
    }

    return sum_of_squared_diffs / static_cast<Real>(data.size() - 1);
}

Real standard_deviation(const std::vector<Real>& data) {
    return std::sqrt(variance(data));
}

Real standard_error(const std::vector<Real>& data) {
    if (data.empty()) {
        throw std::invalid_argument("standard_error requires non-empty data");
    }
    return standard_deviation(data) / std::sqrt(static_cast<Real>(data.size()));
}

Real covariance(const std::vector<Real>& x, const std::vector<Real>& y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("covariance requires equal-length vectors");
    }
    if (x.size() < 2) {
        throw std::invalid_argument("covariance requires at least two data points");
    }

    Real mean_x = 0.0;
    Real mean_y = 0.0;
    Real co_moment = 0.0;

    for (Size i = 0; i < x.size(); ++i) {
        Real n = static_cast<Real>(i + 1);
        Real dx = x[i] - mean_x;
        mean_x += dx / n;
        Real dy = y[i] - mean_y;
        mean_y += dy / n;
        co_moment += dx * (y[i] - mean_y);
    }

    return co_moment / static_cast<Real>(x.size() - 1);
}

Real correlation(const std::vector<Real>& x, const std::vector<Real>& y) {
    Real cov = covariance(x, y);
    Real sd_x = standard_deviation(x);
    Real sd_y = standard_deviation(y);

    if (sd_x == 0.0 || sd_y == 0.0) {
        throw std::invalid_argument("correlation undefined for zero-variance data");
    }

    return cov / (sd_x * sd_y);
}

}
}
