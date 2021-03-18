#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Stock.cpp"

using namespace std;

class StockMarket
{
private:
	vector<Stock> stocks;

public:


	bool createStock(string stockName, double stockPrice, int numberOfShares)
	{
		Stock s(stockName, stockPrice, numberOfShares);
		stocks.push_back(s);
	}

	bool buyOrder(Stock &s, int numberOfShares)
	{

	}
	
	bool sellOrder(Stock s, int numberOfShares)
	{

	}

};