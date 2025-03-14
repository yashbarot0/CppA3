#ifndef INSTRUMENTS_H_VK2TICXL
#define INSTRUMENTS_H_VK2TICXL
#include <vector>
#include <iostream>

/**
 * @brief Abstract Base Class Trade
 * 	This class represents the concept of a trade i.e. something we buy, or a contract that we enter into
 */
class Trade
{
public:
        // (1) Define copy and move constructors as default
        Trade(const Trade&) = default;
        Trade(Trade&&) = default;

        // (2) Delete assignment operators
        Trade& operator=(const Trade&) = delete;
        Trade& operator=(Trade&&) = delete;

	/**
	 * @brief Default constructor for Trade class
	 * 	This sets the value of cost equal to zero
	 */
	Trade() : cost {0}{
		std::cout << "Trade (base class) Constructor (Default)\n";
	}

	/**
	 * @brief Constructor for Trade class
	 *
	 * @param[in] cost This parameter is the price you paid to purchase, or enter the trade
	 */
	Trade (double const cost) : cost {cost} {
		std::cout << "Trade (base class) Constructor (overloaded)\n";
	}

	/**
	 * @brief Destructor for Trade
	 */
	virtual ~Trade (){
		std::cout << "Trade (base class) Destructor\n";
	}

	// (3) declare payoff as a pure virtual constant member function
	virtual double payoff(double const ST) const = 0;

	// (4) Grant access to private member of this class to any non-member functions that need it
	friend double portfolio_payoff(std::vector<Trade const*> const& trades, double const S_T);
	friend double portfolio_profit(std::vector<Trade const*> const& trades, double const S_T);

private:
	double const cost;	///< Holds the premium, or cost paid to enter the trade
};

/**
 * @brief Class to represent a forward trade
 */
class Forward : public Trade
{
public:
	// Explicitly delete the default constructor
	Forward() = delete;

	// Constructor with forward price
	Forward(double fp) : Trade(0), forward_price(fp) {
		std::cout << "Constructor for Forward with forward price " << fp << '\n';
	}

	// Override the payoff function
	double payoff(double const ST) const override {
		return ST - forward_price;
	}

	~Forward() {
		std::cout << "Deleting Forward with forward price " << forward_price << '\n';
	}

private:
	double const forward_price;
};

/**
 * @brief Class to represent a Call Option
 */
class Call : public Trade
{
public:
	// Explicitly delete the default constructor
	Call() = delete;

	// Constructor with strike price and cost
	Call(double cost, double k) : Trade(cost), strike(k) {
		std::cout << "Creating Call with strike " << k << ". Premium paid " << cost << '\n';
	}

	// Override the payoff function
	double payoff(double const ST) const override {
		return std::max(ST - strike, 0.0);
	}

	~Call() {
		std::cout << "Destroying Call with strike " << strike << '\n';
	}

private:
	double const strike;
};

/**
 * @brief Class to represent a Put Option
 */
class Put : public Trade
{
public:
	// Explicitly delete the default constructor
	Put() = delete;

	// Constructor with strike price and cost
	Put(double cost, double k) : Trade(cost), strike(k) {
		std::cout << "Creating Put with strike " << k << ". Premium paid " << cost << '\n';
	}

	// Override the payoff function
	double payoff(double const ST) const override {
		return std::max(strike - ST, 0.0);
	}

	~Put() {
		std::cout << "Destroying Put with strike " << strike << '\n';
	}

private:
	double const strike;
};

#endif /* end of include guard: INSTRUMENTS_H_VK2TICXL */