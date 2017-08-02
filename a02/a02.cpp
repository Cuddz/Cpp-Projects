//Sources: textbook
#include <iostream>
#include <iomanip>
using namespace std;



int main() {

	const float KILOMETER_CONVERSION = 1.609,
		LITER_CONVERSION = 3.785;

	float milesStart,
		milesEnd,
		milesTraveled,
		gallonStart,
		gallonEnd,
		gallonsUsed,
		milesPerGallon,
		kilometersTraveled,
		litersUsed,
		litersPer100kms;

	//Get all the users information
	cout << "Enter starting mileage: " << fixed << setprecision(2);
	cin >> milesStart;
	cout << "Enter ending mileage: ";
	cin >> milesEnd;

	cout << "Enter fuel at start in gallons: ";
	cin >> gallonStart;
	cout << "Enter fuel at end in gallons: ";
	cin >> gallonEnd;

	//Calculate miles traveled, fuel used, and MPG
	milesTraveled = milesEnd - milesStart;
	gallonsUsed = gallonStart - gallonEnd;
	milesPerGallon = milesTraveled / gallonsUsed;
	cout << "Number of miles traveled = " << milesTraveled << " miles" << endl;
	cout << "Fuel used = " << gallonsUsed << endl;
	cout << "Miles per gallon of fuel = " << milesPerGallon << endl << endl;

	//Calculate the conversions
	kilometersTraveled = milesTraveled * KILOMETER_CONVERSION;
	litersUsed = gallonsUsed * LITER_CONVERSION;
	litersPer100kms = (LITER_CONVERSION * 100) / (milesPerGallon * KILOMETER_CONVERSION);
	cout << "Number of kms travled = " << kilometersTraveled << endl;
	cout << "Fuel used = " << litersUsed << " liters" << endl;
	cout << "Liters per 100kms = " << litersPer100kms << endl;

	return 0;
}
