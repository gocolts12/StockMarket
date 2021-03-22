#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "StockMarket.h"

using namespace std;

Stock StockMarket::createStock(string stockName, double stockPrice, int numberOfShares)
{
	Stock s(stockName, stockPrice);
	addStockToMarket(s, numberOfShares);
	return s;
}

//returns successful/unsuccessful
bool StockMarket::buyOrder(Stock &s, int numberOfShares)
{
	auto it = stocks.find(s);
	if (it == stocks.end()) //confirm the stock is on the market
	{
		cout << "invalid stock. " << s.getStockName() << " not found on the market" << endl;
		return false; 
	}
	if (it->second < numberOfShares) // confirm enough shares in float
	{ 
		cout << "Not enough available shares for " << s.getStockName() << " found on the market" << endl;
		return false;
	}
		
	it->second -= numberOfShares;
	cout << "Buy order successful, " << numberOfShares << " purchased" << endl;
		
	return true;
}
	
//returns successful/unsuccessful
bool StockMarket::sellOrder(Stock s, int numberOfShares)
{
	auto it = stocks.find(s);
	if (it == stocks.end()) return false; //confirm the stock is on the market
	//if (it->second < numberOfShares) return false; // confirm enough shares in float

	it->second += numberOfShares;
	cout << "Sell order successful, " << numberOfShares << " sold" << endl;

	return true;
}

void StockMarket::addStockToMarket(Stock& s, int numberOfShares)
{
	if (stocks.find(s) != stocks.end())
	{
		cout << "stock already exists" << endl;
		return;
	}
	stocks.insert(make_pair(s, numberOfShares));

}

void StockMarket::updateStockPrice()
{

}
