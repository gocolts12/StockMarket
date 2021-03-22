#pragma once
#include <iostream>
#include <string>
#include "Stock.h"

using namespace std;


Stock::Stock(string n, double p)
{
	stockName = n;
	stockPrice = p;
}

double Stock::getPrice()
{
	return stockPrice;
}

void Stock::updatePrice(double newPrice)
{
	stockPrice = newPrice;
}

string const Stock::getStockName() const
{
	return stockName;
}

bool Stock::operator<(const Stock& s)const
{
	return this->stockName < s.getStockName();
}
