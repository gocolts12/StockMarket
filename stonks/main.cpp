#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "StockMarket.cpp"
#include "Stock.cpp"
#include "Investor.cpp"



using namespace std;

int main()
{

	StockMarket* market = new StockMarket;
	Investor a("Steve", market);
	Investor b("Emily", market);
	Investor c("Mikey", market);


	Stock s1("Carson Wentz", 7.0, 100);
	Stock s2("Oshane Xmines", 3.0, 150);
	Stock s3("Russell Wilson", 15.0, 50);

	market->addStock(s1);
	market->addStock(s2);
	market->addStock(s3);


}