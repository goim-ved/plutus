#include "../../includes/plutus/core/normal.hpp"
#include "../../includes/plutus/core/constants.hpp"
#include <cmath>
#include <algorithm>
#include <limits>

namespace plutus {
namespace math {

Real normal_pdf(Real x) {
    return constants::INV_SQRT_2PI * std::exp(-0.5 * x * x);
}

Real normal_cdf(Real x) {
    return 0.5 * std::erfc(-x * constants::INV_SQRT_2);
}

Real normal_inv(Real p) {
    return 0;
}

}
}