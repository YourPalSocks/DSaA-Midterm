#pragma once
#ifndef _RAINFALL
#define _RAINFALL

#include "LinkedList.h";
#include <assert.h>
#include <string>
using namespace std;

class Rainfall {
public:
	bool addMonth(string month, int rain);
	bool editMonth(string month, int rain);
	string getInfo();

private:
	//Two parallel LinkedLists to keep track of months and the rain
	LinkedList<int> rainList;
	LinkedList<string> monthList;
	int listLength = 0;

	int getTotal();
	int getAverage();
	int getMost();
	int getLeast();
};
#endif