#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Stock.cpp"

using namespace std;

class StockMarket
{
private:

	map<Stock, int> stocks;

public:


	bool createStock(string stockName, double stockPrice, int numberOfShares)
	{
		Stock s(stockName, stockPrice);
		stocks[s] = numberOfShares;
	}

	//returns successful/unsuccessful
	bool buyOrder(Stock &s, int numberOfShares)
	{

	}
	
	//returns successful/unsuccessful
	bool sellOrder(Stock s, int numberOfShares)
	{

	}

	void addStock(Stock& s)
	{

	}

	void updateStockPrice()
	{

	}

};