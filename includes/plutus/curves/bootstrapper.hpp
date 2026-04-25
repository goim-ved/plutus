#pragma once

#include "yield_curve.hpp"
#include "../core/types.hpp"

#include <vector>

namespace plutus {
namespace curves {

class CurveBootstrapper {
public:
    static YieldCurve bootstrap(const std::vector<MarketInstrument>& instruments,
                                InterpolationMethod method = InterpolationMethod::LogLinear);
    
    static YieldCurve from_rates(const std::vector<Real>& maturities,
                                 const std::vector<Real>& rates,
                                 InterpolationMethod method = InterpolationMethod::LogLinear);
};

}
}

