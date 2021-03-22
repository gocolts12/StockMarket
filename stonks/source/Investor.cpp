#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "Investor.h"

using namespace std;

Investor::Investor(string n, StockMarket *SM)
{
	investorName = n;
	availableFunds = 0;
	stockMarket = SM;
}

bool Investor::sendBuyOrder(Stock s, int numberOfShares)
{
	//If we don't have the funds for the trade
	if (s.getPrice() * numberOfShares > availableFunds)
	{
		cout << "Order failed, insufficient funds" << endl;
		return false;
	}

	//Confirm that the market could execute your trade
	//The market will print the error reason
	if (!stockMarket->buyOrder(s, numberOfShares)) return false;

	availableFunds -= s.getPrice() * numberOfShares;

	auto it = portfolio.find(s);
	if (it == portfolio.end())
	{
		portfolio.emplace(make_pair(s, numberOfShares));
		cout << investorName << " successfully purchased " << numberOfShares << " of " << s.getStockName() << endl;
		return true;
	}
	it->second += numberOfShares;
	
	cout << investorName << " successfully purchased " << numberOfShares << " shares of " << s.getStockName() << endl;
	return true;

}

bool Investor::sendSellOrder(Stock s, int numberOfShares)
{
	//If we don't own the stock
	auto it = portfolio.find(s);
	if (it == portfolio.end())
	{
		cout << "You don't own this stock, order failed" << endl;
		return false;
	}
	//If we don't own enough shares of the stock
	if (numberOfShares > it->second)
	{
		cout << "Order failed, you don't own enough shares" << endl;
		return false;
	}

	//Confirm that the market could execute your trade
	//The market will print the error reason
	if (!stockMarket->sellOrder(s, numberOfShares)) return false;


	availableFunds += s.getPrice() * numberOfShares;
	it->second -= numberOfShares;

	cout << investorName << " successfully sold " << numberOfShares << " of " << s.getStockName() << endl;
	return true;
}

void Investor::depositFunds(double funds)
{
	availableFunds += funds;
}
void Investor::withdrawFunds(double funds)
{
	availableFunds -= funds;
}