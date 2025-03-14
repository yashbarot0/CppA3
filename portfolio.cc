#include "portfolio.h"
#include "instruments.h"

double portfolio_payoff(std::vector<Trade const*> const& trades, double const S_T) {
	double total_payoff = 0.0;
	for (auto const trade : trades) {
		total_payoff += trade->payoff(S_T);
	}
	return total_payoff;
}

double portfolio_profit(std::vector<Trade const*> const& trades, double const S_T) {
	double total_profit = 0.0;
	for (auto const trade : trades) {
		total_profit += trade->payoff(S_T) - trade->cost;
	}
	return total_profit;
}