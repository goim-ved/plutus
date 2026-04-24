#pragma once

#include "types.hpp"

namespace plutus {
namespace math {

Real normal_pdf(Real x); // Probablity Density Function
Real normal_cdf(Real x); // Cumulative Distribution Function
Real normal_inv(Real p); // Inverse CDF

}
}