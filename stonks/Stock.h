#pragma once
#include <iostream>
#include <string>

#ifndef Stock_H
#define Stock_H

using namespace std;

class Stock
{
private:
	string stockName;
	double stockPrice;

public:

	Stock(string n, double p);

	double getPrice();

	void updatePrice(double newPrice);

	const string getStockName() const;

	bool operator<(const Stock& s)const;
};
#endif