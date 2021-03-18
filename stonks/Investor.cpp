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
		//If we don't have the funds for the trade
		if (s.getPrice() * numberOfShares > availableFunds)
		{
			cout << "Order failed" << endl;
			return false;
		}

		//Confirm that the market could execute your trade
		//The market will print the error reason
		if (!stockMarket->buyOrder(s, numberOfShares)) return false;

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

	bool sendSellOrder(Stock s, int numberOfShares)
	{
		//If we don't own the stock
		if (portfolio.find(s) == portfolio.end())
		{
			cout << "You don't own this stock, order failed" << endl;
			return false;
		}
		//If we don't own enough shares of the stock
		if (numberOfShares > portfolio[s])
		{
			cout << "Order failed, you don't own enough shares" << endl;
			return false;
		}

		//Confirm that the market could execute your trade
		//The market will print the error reason
		if (!stockMarket->sellOrder(s, numberOfShares)) return false;


		availableFunds += s.getPrice() * numberOfShares;
		portfolio[s] -= numberOfShares;

		cout << "Order successful" << endl;
		return true;
	}

};