#include "Rainfall.h"

#include <iostream> // Used for Debugging

/** Add a month of rain stats to the list
* @param month The month to add
* @param rain The amount of rain to add (in inches)
* @return True if operation was successful, false otherwise
*/
bool Rainfall::addMonth(string month, int rain)
{
	//Check for double entries
	for (int x = 1; x < monthList.getLength(); x++)
	{
		if (monthList.getEntry(x)._Equal(month))
		{
			// Double entry found, returnoing
			return false;
		}
	}
	bool check = rainList.insert(listLength + 1, rain);
	bool secondcheck = monthList.insert(listLength + 1, month);
	listLength++;
	assert(check && secondcheck);
	return (check && secondcheck);
}

/** Edit a month's entry of rain stats
* @param month The month to edit
* @param rain The new rain value
* @return True if operation was successful, false otherwise
*/
bool Rainfall::editMonth(string month, int rain)
{
	// Make sure entry exists
	for (int x = 1; x <= monthList.getLength(); x++)
	{
		if (monthList.getEntry(x) == month) // Month found
		{
			rainList.setEntry(x, rain);
			return true;
		}
	}
	return false;
}

/** Returns total, average, maximum, and minimum
*/
string Rainfall::getInfo()
{
	//Get indeces for max and min
	int max = getMost();
	int min = getLeast();
	//Make sure stuff isn't empty
	if (rainList.isEmpty())
	{
		return "ERROR: Database is empty";
	}
	//Build string with various private methods
	string toRet = "Total Rainfall: " + to_string(getTotal()) + " inches" + '\n';
	toRet += "Average Rainfall: " + to_string(getAverage()) + " inches" + '\n';
	toRet += "Most Rainfall: " + monthList.getEntry(max) + " had " + to_string(rainList.getEntry(max)) + " inches" + '\n';
	toRet += "Least Rainfall: " + monthList.getEntry(min) + " had " + to_string(rainList.getEntry(min)) + " inches" + '\n';

	//Return final string to be printed
	return toRet;
}

/** Get sum of all rain amounts
* @return Sum of rainList entries
*/
int Rainfall::getTotal()
{
	int total = 0;
	for (int x = 1; x <= monthList.getLength(); x++)
	{
		total += rainList.getEntry(x);
	}
	return total;
}

/** Get average of all rain amounts
* @return Average of rainList entries
*/
int Rainfall::getAverage()
{
	int total = 0;
	for (int c = 1; c <= monthList.getLength(); c++)
	{
		total += rainList.getEntry(c);
	}
	return total / listLength;
}

int Rainfall::getMost()
{
	int index = 1;
	for (int x = 1; x <= monthList.getLength(); x++)
	{
		if (rainList.getEntry(x) > rainList.getEntry(index))
		{
			index = x;
		}
	}
	return index;
}

int Rainfall::getLeast()
{
	int index = 1;
	for (int x = 1; x <= monthList.getLength(); x++)
	{
		if (rainList.getEntry(x) < rainList.getEntry(index))
		{
			index = x;
		}
	}
	return index;
}
