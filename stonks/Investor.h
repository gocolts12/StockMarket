#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Stock.h"
#include "StockMarket.h"

#ifndef Investor_H
#define Investor_H

using namespace std;

class Investor
{
private:
	string investorName;
	double availableFunds;
	map<Stock, int> portfolio;
	StockMarket* stockMarket;
	double portfolioValue;

public:

	Investor(string n, StockMarket* SM);

	bool sendBuyOrder(Stock s, int numberOfShares);

	bool sendSellOrder(Stock s, int numberOfShares);

	void depositFunds(double funds);

	void withdrawFunds(double funds);

};

#endif