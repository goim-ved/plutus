#pragma once

#include "types.hpp"

namespace plutus {
namespace constants {

constexpr Real PI = 3.14159265358979323846;
constexpr Real TWO_PI = 6.28318530717958647692;
constexpr Real SQRT_2PI = 2.50662827463100050242;
constexpr Real INV_SQRT_2PI = 0.39894228040143267794;
constexpr Real SQRT_2 = 1.41421356237309504880;
constexpr Real INV_SQRT_2 = 0.70710678118654752440;
constexpr Real DAYS_PER_YEAR = 365.25; //taking in account leap year
constexpr Real DEFAULT_TOLERANCE = 1e-10;
constexpr Size DEFAULT_MAX_ITERATIONS = 1000; //so system doesnt keep looping
constexpr Real EPSILON = 1e-15;

}
}