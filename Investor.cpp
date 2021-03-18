#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Stock.cpp"
#include "StockMarket.cpp"

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

	Investor(string n, StockMarket *SM)
	{
		investorName = n;
		availableFunds = 100.0;
		stockMarket = SM;
	}

	bool sendBuyOrder(Stock s, int numberOfShares)
	{
		if (stockMarket->buyOrder(s, numberOfShares));
		{
			availableFunds -= s.getPrice() * numberOfShares;
			if (portfolio.find(s) == portfolio.end())
			{
				portfolio.emplace(make_pair(s, numberOfShares));
			}
			else 
			{
				portfolio[s] += numberOfShares;
			}
			return true;
		}
			cout << "Order failed" << endl;
			return false;
	}

	bool sendSellOrder(Stock s, int numberOfShares)
	{
		if (stockMarket->sellOrder(s, numberOfShares));
		{
			availableFunds -= s.getPrice() * numberOfShares;
			if (portfolio.find(s) == portfolio.end())
			{
				portfolio.emplace(make_pair(s, numberOfShares));
			}
			else
			{
				portfolio[s] += numberOfShares;
			}
			cout << "Order successful" << endl;
			return true;
		}
			cout << "Order failed" << endl;
			return false;
	}

};