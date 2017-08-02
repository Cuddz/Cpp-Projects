//Sources: me

#include <iostream>
using namespace std;

int main() {
    
    //Passenger fares
    const float BIKE_FEE = 2.00,
    ADULT_FEE = 12.95,
    SENIOR_FEE = 6.45,
    YOUTH_FEE = 6.45;
    
    //Vehicle and driver fares for vehicles under 20'
    const float UNDER_14_DRIVER = 36.05,
    UNDER_14_SENIOR = 29.55,
    UNDER_22_DRIVER = 45.00,
    UNDER_22_SENIOR = 38.50,
    UNDER_14_OVER_7 = 35.80,
    UNDER_22_OVER_7 = 44.75;
    
    //Vehicle length fares
    const float UNDER_30_UNDER_7 = 69.60,
    UNDER_30_OVER_7 = 138.95,
    UNDER_40_TO_30 = 185.95,
    UNDER_50_TO_40 = 232.95;
    
    float total = 0;
    
    int adultPassengers,
    seniorPassengers,
    youthPassengers,
    vehicleLength,
    bikes;
    
    bool seniorDriver = false;
    
    char reply;
    
    cout << "Welcome to Bennett's Fare Calculator\n"
    << "Are you driving a vehicle onto the ferry? (y/n): ";
    cin >> reply;
    
    //Driving on the ferry
    if(reply == 'y'){
        cout << "Is the driver a senior citizen (65 or over) or disabled? (y/n): ";
        cin >> reply;
        if(reply == 'y') seniorDriver = true;
        
        //Getting number of passengers and age
        cout << "How many passengers in your vehicle? (excluding the driver)"
        << "\nAdults (age 19 – 64): ";
        cin >> adultPassengers;
        total += adultPassengers * ADULT_FEE;

        cout << "Senior Citizens (65 or older), or Disabled Persons: ";
        cin >> seniorPassengers;
        total += seniorPassengers * SENIOR_FEE;

        cout << "Youth (5 - 18 years old): ";
        cin >> youthPassengers;
        total += youthPassengers * YOUTH_FEE;

        //Get vehicle information
        cout << "Is your vehicle over 7 feet, 6 inches in height? (y/n): ";
        cin >> reply;
        
        if(reply == 'n'){
            cout << "How long is your vehicle in feet: ";
            cin >> vehicleLength;
            
            if(vehicleLength < 14 && seniorDriver)
                total += UNDER_14_SENIOR;
            
            else if(vehicleLength < 14 && !seniorDriver)
                total += UNDER_14_DRIVER;
            
            else if(vehicleLength < 22 && seniorDriver)
                total += UNDER_22_SENIOR;
            
            else if(vehicleLength < 22 && !seniorDriver)
                total += UNDER_22_DRIVER;
            
            else if(vehicleLength >= 30 && vehicleLength < 40)
                total += UNDER_40_TO_30;
            
            else if(vehicleLength >= 40 && vehicleLength < 50)
                total += UNDER_50_TO_40;
            
            /*         Vehicle Length base fare            */
            
            else if(vehicleLength >= 22 && vehicleLength < 30)
                total += UNDER_30_UNDER_7;
            
            else
                cout << "Vehicle is prohibited" << endl;
            
        }
        // Over the height limit SURGE
        else{
            cout << "How long is your vehicle in feet: " << endl;
            cin >> vehicleLength;
            
            if(vehicleLength < 14 && seniorDriver)
                total += UNDER_14_OVER_7 + UNDER_14_SENIOR;
            
            else if(vehicleLength < 14 && !seniorDriver)
                total += UNDER_14_OVER_7 + UNDER_14_DRIVER;
                    
            else if(vehicleLength < 22 && seniorDriver){
                total += UNDER_22_OVER_7 + UNDER_22_SENIOR;
            }
            else if(vehicleLength >= 22 && vehicleLength < 30)
                total += UNDER_30_OVER_7;
        }
        
    }
    
    //Not driving on ferry
    else{
        //Getting number of passengers and age
        cout << "How many passengers in your vehicle? (excluding the driver)"
        << "\nAdults (age 19 – 64): ";
        cin >> adultPassengers;
        total += adultPassengers * ADULT_FEE;
        cout << "Senior Citizens (65 or older), or Disabled Persons: ";
        cin >> seniorPassengers;
        total += seniorPassengers * SENIOR_FEE;
        cout << "Youth (5 - 18 years old): ";
        cin >> youthPassengers;
        total += youthPassengers * YOUTH_FEE;

        
    }
    
    cout << "How many people in your group are traveling with a bicycle: ";
    cin >> bikes;
    total += bikes * BIKE_FEE;
    
    cout << "Your total fare is $" << total << endl << "Bennett's Fare Calculator";
    
    return 0;
}




