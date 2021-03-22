#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "StockMarket.h"
#include "Stock.h"
#include "Investor.h"



using namespace std;

int main()
{

	StockMarket* market = new StockMarket;
	Investor steve("Steve", market);
	Investor emily("Emily", market);
	Investor mikey("Mikey", market);
	
	Stock carson = market->createStock("Carson Wentz", 7.0, 500);
	Stock xmines = market->createStock("Oshane Xmines", 3.0, 750);
	Stock russ = market->createStock("Russell Wilson", 15.0, 250);


	steve.sendBuyOrder(xmines, 32);
	steve.depositFunds(1000000);
	steve.sendBuyOrder(xmines, 751);
	steve.sendBuyOrder(xmines, 32);

	emily.depositFunds(1000000);
	emily.sendBuyOrder(xmines, 32);

}