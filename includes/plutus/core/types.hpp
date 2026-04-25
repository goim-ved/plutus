#pragma once

#include <cstddef>
#include <vector>
#include <string>

namespace plutus {

using Real = double;
using Size = std::size_t; // not using int for performance

enum class OptionType {
    Call,
    Put
};

enum class ExerciseStyle {
    European, // need black scholes
    American // monte carlo?
};

enum class BarrierType {
    UpAndIn,
    UpAndOut,
    DownAndIn,
    DownAndOut
};

enum class AveragingType { // for asian options
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
    Real spot; //stock price
    Real strike; //price agreed
    Real rate; //money today > same money a year from now
    Real volatility; //craziness of the stock price xd
    Real maturity; //expiry date of the option
    OptionType type; //call or put
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