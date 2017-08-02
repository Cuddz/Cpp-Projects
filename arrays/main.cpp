//Sources: old code

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name;
    int score[5], total;
    char grade;
    ifstream inFile ("arrays.txt");
    
    while(inFile >> name >> score[0] >> score[1] >> score[2]
          >> score[3] >> score[4]){
        //reset the total and add up the score
        total = 0;
        for(int i = 0; i < 5; i++){
            total += score[i];
        }
        float average = total/5;
        
        if(average >= 90)
            grade = 'A';
        
        else if(average >= 80 && average < 90)
            grade = 'B';
        
        else if(average >= 70 && average < 80)
            grade = 'C';
        
        else if(average >= 60 && average < 70)
            grade = 'D';
        
        else
           grade = 'F';

        cout << name << "'s average test score: " << average << " with a grade of: " << grade << endl;
        
    }
    
    
    return 0;
}

