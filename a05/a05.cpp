//Sources: me
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    
    char reply = NULL;
    string item;
    double total = 0,
    temp;
    
    while (tolower(reply) != 'q' ){
        
        cout << "A) Add an item to cart" << endl
        << "T) Running total" << endl
        << "Q) Quit" << endl;
        cin >> reply;
        
        switch(tolower(reply)){
                
            case 'a':
                cout << "Item name: ";
                getline(cin.ignore(), item);
                cout << "Item price: ";
                cin >> temp;
                total += temp;
                cout << "Total: " << fixed << setprecision(2) << total << endl;
                break;
            
            case 't':
                cout << "Total: " << total << endl;
                break;
            
            case 'q':
                cout << "Total: " << total <<endl;
        }
    }
    
    return 0;
}

