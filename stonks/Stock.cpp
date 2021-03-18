#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stock
{
private:
	string stockName;
	double stockPrice;

public:

	Stock(string n, double p)
	{
		stockName = n;
		stockPrice = p;
	}

	double getPrice()
	{
		return stockPrice;
	}

	void updatePrice(double newPrice)
	{
		stockPrice = newPrice;
	}

};