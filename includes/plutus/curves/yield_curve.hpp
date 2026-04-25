#pragma once

#include "../core/types.hpp"
#include <vector>
#include <string>
#include <utility>

namespace plutus {
namespace curves {

enum class InterpolationMethod {
    LogLinear,
    CubicSpline
};

struct MarketInstrument
{
    Real maturity;
    Real rate;
    std::string instrument_type;
};

class YieldCurve {
public:
    explicit YieldCurve(InterpolationMethod method = InterpolationMethod::LogLinear);

    void add_node(Real maturity, Real discount_factor);
    Real discount_factor(Real maturity) const;
    Real zero_rate(Real maturity) const;
    Real forward_rate(Real t1, Real t2) const;
    Size node_count() const;
    void clear();

private:
    InterpolationMethod method_;
    std::vector<std::pair<Real, Real>> nodes_;
    mutable bool spline_dirty_;
    mutable std::vector<Real> spline_a_;
    mutable std::vector<Real> spline_b_;
    mutable std::vector<Real> spline_c_;
    mutable std::vector<Real> spline_d_;
    mutable std::vector<Real> spline_x_;

    Real interpolate_log_linear(Real maturity) const;
    Real interpolate_cubic_spline(Real maturity) const;
    void build_spline() const;
};

}
}