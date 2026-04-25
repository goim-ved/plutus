#pragma once

#include "types.hpp"
#include <vector>

namespace plutus {
namespace math {

Real mean(const std::vector<Real>& data);
Real variance(const std::vector<Real>& data);
Real standard_deviation(const std::vector<Real>& data);
Real standard_error(const std::vector<Real>& data);
Real covariance(const std::vector<Real>& x, const std::vector<Real>& y);
Real correlation(const std::vector<Real>& x, const std::vector<Real>& y);

}
}