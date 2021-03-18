#pragma once
#include <iostream>
#include <string>

using namespace std;

class Stock
{
private:
	string stockName;
	double stockPrice;
	int numberOfShares;

public:

	Stock(string n, double p, int i)
	{
		stockName = n;
		stockPrice = p;
		numberOfShares = i;
	}

	double getPrice()
	{
		return stockPrice;
	}


};