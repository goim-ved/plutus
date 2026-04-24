#pragma once

#include <cstddef>
#include <vector>
#include <string>

namespace plutus {

using Real = double;
using Size = std::size_t;

enum class OptionType {
    Call,
    Put
};

enum class ExerciseStyle {
    European,
    American
};

enum class BarrierType {
    UpAndIn,
    UpAndOut,
    DownAndIn,
    DownAndOut
};

enum class AveragingType {
    Arithmetic,
    Geometric
};

enum class LookbackType {
    FloatingStrike,
    FixedStrike
};

enum class DigitalPayoffType {
    CashOrNothing,
    AssetOrNothing
};

struct OptionParams {
    Real spot;
    Real strike;
    Real rate;
    Real volatility;
    Real maturity;
    OptionType type;
};

struct PricingResult {
    Real price;
    Real delta;
    Real gamma;
    Real vega;
    Real theta;
    Real rho;
};

}