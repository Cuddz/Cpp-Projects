//Sources: old code

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct StudentType{
    
    string studentFName;
    string studentLName;
    int testScores[5];
    char grade;
};

void ReadInfo(string fileName, StudentType students[], int size);
void GetGrade(StudentType students[], int size);


int main() {
    
    StudentType students[20];
    ReadInfo("students.txt", students, 20);
    GetGrade(students, 20);
    
    //output data
    ofstream outFile ("output.txt");
    for(int i = 0; i < 20; i++){
        outFile << students[i].studentFName << " " <<students[i].studentLName;
        for(int j = 0; j < 5; j++){
            outFile << " " << students[i].testScores[j];
        }
        outFile << " " << students[i].grade << endl;
    }
    outFile.close();
    
    return 0;
}

void ReadInfo(string fileName, StudentType students[], int size){
    
    ifstream inFile (fileName);
    for(int i = 0; i < size; i++){
         inFile >> students[i].studentFName >> students[i].studentLName
        >> students[i].testScores[0] >> students[i].testScores[1]
        >> students[i].testScores[2] >> students[i].testScores[3]
        >> students[i].testScores[4];
    }
    inFile.close();
}

void GetGrade(StudentType students[], int size){
    float total = 0, average;
    
    //calculate their average and get the grade
    for(int i = 0; i < size; i++){
        //reset the total for next student
        total = 0;
        for(int j = 0; j < 5; j++)
            total += students[i].testScores[j];
        average = total / 5;
        
        //determine grade
        if(average >= 90)
            students[i].grade = 'A';
        
        else if(average >= 80 && average < 90)
            students[i].grade = 'B';
        
        else if(average >= 70 && average < 80)
            students[i].grade = 'C';
        
        else if(average >= 60 && average < 70)
            students[i].grade = 'D';
        
        else
            students[i].grade = 'F';
        
    }
}
