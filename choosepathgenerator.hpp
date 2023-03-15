#ifndef choose_path_generator_hpp
#define choose_path_generator_hpp

#include <ql/exercise.hpp>
#include <ql/instruments/barrieroption.hpp>
#include <ql/pricingengines/mcsimulation.hpp>
#include <ql/pricingengines/barrier/mcbarrierengine.hpp>
#include <ql/processes/blackscholesprocess.hpp>
#include <utility>

namespace QuantLib {

    auto getPathGenerator(TimeGrid grid,
                        typename RNG::rsg_type generator,
                        boost::shared_ptr<GeneralizedBlackScholesProcess> process_,
                        bool brownianBridge_,
                        double strike,
                        bool constantParameters) const {
        // Constant Case
        if (constantParameters) {
            ext::shared_ptr<GeneralizedBlackScholesProcess> BS_process =
                ext::dynamic_pointer_cast<GeneralizedBlackScholesProcess>(process_);
            // Retrieve parameters from process
            Time extrac_time = grid.back();
            double riskFreeRate_ = BS_process->riskFreeRate()->zeroRate(extrac_time, Continuous);
            double dividend_ = BS_process->dividendYield()->zeroRate(extrac_time, Continuous);
            double volatility_ = BS_process->blackVolatility()->blackVol(extrac_time, strike);
            double underlyingValue_ = BS_process->x0();
            // Constant Black Scholes process with these parameters
            ext::shared_ptr<ConstantBlackScholesProcess> Constant_BS_process(new ConstantBlackScholesProcess(underlyingValue_, riskFreeRate_, volatility_, dividend_));
            // Return a new path generator with ConstantBlackScholesProcess
            return ext::shared_ptr<path_generator_type>(
                new path_generator_type(Constant_BS_process, grid,
                    generator, brownianBridge_));
        } else { // Not constant case
            return ext::shared_ptr<path_generator_type>(
                        new path_generator_type(process_,
                                    grid, generator, brownianBridge_));
        }
    }

}

#endif