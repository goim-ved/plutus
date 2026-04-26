#pragma once 

#include "core/types.hpp"

namespace plutus {
namespace models {

class BlackScholes {
public:
    static PricingResult price(const OptionParams& params);

    static Real call_price(Real spot, Real strike, Real rate, Real vol, Real maturity);
    static Real put_price(Real spot, Real strike, Real rate, Real vol, Real maturity);

private:
    static void validate(Real spot, Real strike, Real vol, Real maturity);

};    

}
}