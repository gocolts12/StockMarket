#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Stock.h"

#ifndef StockMarket_H
#define StockMarket_H

using namespace std;

class StockMarket
{
private:

	map<Stock, int> stocks;

public:

	Stock createStock(string stockName, double stockPrice, int numberOfShares);
	bool buyOrder(Stock& s, int numberOfShares);
	bool sellOrder(Stock s, int numberOfShares);
	void addStockToMarket(Stock& s, int numberOfShares);
	void updateStockPrice();

};
#endif