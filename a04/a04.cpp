//Sources: textbook
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    string filePath,
    line,
    name,
    school;
    
    char gender;
    
    ofstream outFile;
    ifstream inFile;
    
    int numMales = 0,
    numFemales = 0,
    numCommunity = 0,
    numUniversity = 0;
    
    float maleAverage,
    maleTotal = 0,
    femaleAverage,
    femaleTotal = 0,
    communityTotal = 0,
    communityAverage,
    universityTotal = 0,
    universityAverage,
    score,
    totalScore = 0;
    
    //Get the file path and open file
    cout << "Enter the file name with path: ";
    getline(cin, filePath);
    inFile.open(filePath);
    
    //Close if it can't open/find file
    if(!inFile.is_open()){
        cout << "Error: couldn't open file";
        return 0;
    }
    
    while(inFile >> name >> gender >> school >> score){
        //echo
        cout << name << " " << gender << " " << school << " " << score << endl;
        
        //Get all the info from file
        if(gender == 'M'){
            maleTotal += score;
            totalScore += score;
            numMales++;
            if(school == "CC"){
                communityTotal += score;
                numCommunity++;
            }
            else{
                universityTotal += score;
                numUniversity++;
                totalScore += score;
            }
        }
        else{
            femaleTotal += score;
            numFemales++;
            totalScore += score;
            if(school == "CC"){
                communityTotal += score;
                numCommunity++;
                totalScore += score;
            }
            else{
                universityTotal += score;
                numUniversity++;
                totalScore += score;
            }
        }
    }
    //Calulate the averages
    maleAverage = maleTotal / numMales;
    femaleAverage = femaleTotal / numFemales;
    communityAverage = communityTotal / numCommunity;
    universityAverage = universityTotal / numUniversity;
    
    cout << fixed << setprecision(2) << "\nMale Average: " << maleAverage << endl
    << "Female Average: " << femaleAverage << endl
    << "Community College Average: " << communityAverage << endl
    << "University Average: " << universityAverage << endl;
    
    cout << "Average Of All Students: " << (maleTotal + femaleTotal) / (numMales + numFemales);
    
    return 0;
}
