//Sources: me
#include <iostream>

using namespace std;

int largest();
void numberCounter(int number, int &oddCount, int &evenCount, int &zeroCount);

int main() {
    char reply = NULL;
    
    while(tolower(reply) != 'c'){
        
        cout << "Welcome to my program! Please choose one of the following: " << endl
        << "(a) Find the largest of a list of positive numbers (-1 to quit)." << endl
        << "(b) Given a positive number, display the number of even, odd and zero digits in"
        << "the number." << endl
        << "(c) quits the program " << endl;
        
        cin >> reply;
        
        switch(tolower(reply)){
               
            case 'a':
                cout << largest() << endl;
                break;
                
            case 'b':
                cout << "enter a number: ";
                int number,
                oddCount,
                evenCount,
                zeroCount;
                cin >> number;
                numberCounter(number, oddCount, evenCount, zeroCount);
                break;
            
            case 'c':
                return 0;
            
            default:
                "Error: invalid input";
            
        }
    }
    return 0;
}

int largest(){
    
    int stop = -1,
    largest = 0,
    temp = 0;
    
    while(temp != stop){
        cout << "enter a number: ";
        cin >> temp;
        if(temp > largest)
            largest = temp;
    }
    cout << "Your largest number was: ";
    return largest;
    
}

void numberCounter(int number, int &oddCount, int &evenCount, int &zeroCount){
    oddCount = 0;
    evenCount = 0;
    zeroCount = 0;
    
    //break up the number
    int temp;
    while(number != 0){
        
        temp = number % 10;
        if(temp % 2 == 0)
            evenCount++;
        else if(temp == 0)
            zeroCount++;
        else
            oddCount++;
        number /= 10;
        
    }
    
    cout << "Even numbers: " << evenCount << " Odd numbers: " << oddCount
    << " Zero count: " << zeroCount << endl;
}
