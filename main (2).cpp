#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

#include "DataInput.hpp"
using namespace std;

int main() {
    // Initialization and File Check
    ifstream humanFile("human-crew.txt");

    ifstream alienFile("alien-crew.txt");

    linkedList<HU::Human> humanList;
    linkedList<AL::Alien> alienList;
    loadFile(alienFile, alienList, humanFile, humanList);
    linkedList<CrewMember*>* mergedList;
    
    bool running = true;
    char choice;

    while (running) {
        cout << "Select sorting option:" << endl
             << "A. Insertion into Human Crew and Alien Crew lists." << endl
             << "B. Search operation by ID, Training Score, Mission Amplitude, and Name." << endl
             << "C. Delete by Name and delete‑head‑and‑tail behavior." << endl
             << "D. Merge operation correctness and ordering." << endl
             << "E. Print out alien and human lists."
             << "F. Advanced search function (Innovation) " << endl
             << "G. Exit the program." << endl;

        cin >> choice;
        //In case if the user enters a lot of enters
        cin.ignore(10000, '\n');

        choice = toupper(choice);//Turn the choice into upper case

    switch (choice) {
    case 'A': {
        cout << "Selecting insertion option:" << endl
             << "A. Insertion into Human Crew list." << endl
             << "B. Insertion into Alien Crew list." << endl; 

        cin >> choice;
        cin.ignore(10000, '\n');
        choice = toupper(choice);//Turn the choice into upper case


        if (choice != 'A' && choice != 'B') {
            cout << "Incorrect choice, enter A or B" << endl; //just send no matching command found or unidentify comma
            continue; // Go back to the main menu
        }
        else if (choice == 'A') {
            // Insertion into Human Crew list
            cout << "Enter the first name, last name, home sector, training score, and mission aptitude." << endl;

            string inputline;
            getline(cin, inputline);
            HU::Human inputHuman;
            loadHuman(inputline, inputHuman);
            humanList.insertElement(inputHuman);
        }
        else if (choice == 'B') {
            // Insertion into Alien Crew list
            cout << "Enter the first name, last name, home world, training score, , mission aptitude" << endl
            << "signal strength, cognitive link, emphathic overlay, cognitive resistance, and total.";

            string inputline;
            getline(cin, inputline);
            AL::Alien inputAlien;
            loadAlien(inputline, inputAlien);
            alienList.insertElement(inputAlien);
        }
    }

    case 'B': {
        cout << "Selecting searching operation option:" << endl
             << "A. Searching operation by ID." << endl
             << "B. Searching operation by Training Score." << endl
             << "C. Searching operation by Mission Amplitude." << endl
             << "D. Searching operation by Name." << endl;
            
        cin >> choice;
        cin.ignore(10000, '\n');
        choice = toupper(choice);//Turn the choice into upper case


        if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'D') {
            cout << "Incorrect choice, enter A, B, C or D" << endl; //just send no matching command found or unidentify comma
            continue; // Go back to the main menu
        }

        else if (choice == 'A') {
            
            cout << "Enter A for alien and B for human" << endl;
            cin >> choice;
            cin.ignore(10000, '\n');
            choice = toupper(choice);//Turn the choice into upper case
            if (choice != 'A' && choice != 'B') {
                cout << "Incorrect choice, enter A or B" << endl; //just send no matching command found or unidentify comma
                continue; // Go back to the main menu
            }

            cout << "Enter the ID to search" << endl;
            int IDinput;
            cin >> IDinput;

            if (choice == 'A') {
                alienList.IDsearch(IDinput);
            }
            else if (choice == 'B') {
                humanList.IDsearch(IDinput);
            }
        }

        else if (choice == 'B') {
            
            cout << "Enter A for alien and B for human" << endl;
            cin >> choice;
            cin.ignore(10000, '\n');
            choice = toupper(choice);//Turn the choice into upper case
            if (choice != 'A' && choice != 'B') {
                cout << "Incorrect choice, enter A or B" << endl; //just send no matching command found or unidentify comma
                continue; // Go back to the main menu
            }

            cout << "Enter the training score to search" << endl;
            float Tinput;
            cin >> Tinput;

            if (choice == 'A') {
                alienList.scoreSearch(Tinput);
            }
            else if (choice == 'B') {
                humanList.scoreSearch(Tinput);
            }
        }
        
        else if (choice == 'C') {
            
            cout << "Enter A for alien and B for human." << endl;
            cin >> choice;
            cin.ignore(10000, '\n');
            choice = toupper(choice);//Turn the choice into upper case
            if (choice != 'A' && choice != 'B') {
                cout << "Incorrect choice, enter A or B" << endl; //just send no matching command found or unidentify comma
                continue; // Go back to the main menu
            }

            cout << "Enter the mission aptitude to search." << endl;
            int MAinput;
            cin >> MAinput;

            if (choice == 'A') {
                alienList.aptitudeSearch(MAinput);
            }
            else if (choice == 'B') {
                humanList.aptitudeSearch(MAinput);
            }
        }

        else if (choice == 'D') {
            
            cout << "Enter A for alien and B for human." << endl;
            cin >> choice;
            cin.ignore(10000, '\n');
            choice = toupper(choice);//Turn the choice into upper case
            if (choice != 'A' && choice != 'B') {
                cout << "Incorrect choice, enter A or B." << endl; //just send no matching command found or unidentify comma
                continue; // Go back to the main menu
            }

            cout << "Enter the First Name to search." << endl;
            cout << "Enter the Last Name to search." << endl;
            string Finput;
            string Linput;
            cin >> Finput;
            cin >> Linput;
            

            if (choice == 'A') {
                alienList.nameSearch(Finput, Linput);
            }
            else if (choice == 'B') {
                humanList.nameSearch(Finput, Linput);
            }
        }
    }
    case 'C': {
        cout << "Selecting deletion option:" << endl
        << "A. Delete by Name." << endl;
        
        cout << "Enter A for alien and B for human" << endl;
        cin >> choice;
        cin.ignore(10000, '\n');
        choice = toupper(choice);//Turn the choice into upper case
        if (choice != 'A' && choice != 'B') {
            cout << "Incorrect choice, enter A or B" << endl; //just send no matching command found or unidentify comma
            continue; // Go back to the main menu
        }

        cout << "Enter the First Name to delete." << endl;
        cout << "Enter the Last Name to delete." << endl;
        string Finput;
        string Linput;
        cin >> Finput;
        cin >> Linput;

        if (choice == 'A') {
            alienList.nameRemove(Finput, Linput);
        }
        else if (choice == 'B') {
            humanList.nameRemove(Finput, Linput);
        }
    }
    case 'D': {
        cout << "Merging alien and human lists." << endl;
        mergedList = linkedList<CrewMember*>::merge(humanList, alienList);
        if (mergedList != nullptr) {
            mergedList->print();
        }
    }
    case 'E': {
        cout << "Selectinng list print out option:" << endl
             << "A. Print alien list and human list synchronically." << endl
             << "B. Print alien list."<< endl
             << "C. Print human list." << endl;
         
        cin >> choice;
        cin.ignore(10000, '\n');
        choice = toupper(choice);//Turn the choice into upper case
        
        if (choice != 'A' && choice != 'B' && choice != 'C') {
                cout << "Incorrect choice, enter A B or C" << endl; //just send no matching command found or unidentify comma
                continue; // Go back to the main m
            }

            cout << "Enter the list to print out." << endl;
            char Ltinput;
            cin >> Ltinput;

            
            if (Ltinput == 'A') {
                if (mergedList != nullptr) {
                    mergedList->print();
                }
                else if (mergedList == nullptr) {
                    linkedList<CrewMember*>* mergedList;
                    mergedList = linkedList<CrewMember*>::merge(humanList, alienList);
                    mergedList->print();
                }
            }
            else if (Ltinput == 'B') {
                alienList.print();
            }
            else if (Ltinput == 'C') {
                humanList.print();
            }
    }
    case 'F': { //Advanced search function
        cout << "Advanced search option:" << endl;
        cout << "this function allows users to search by name with partial matches for first and last names." << endl;
        cout << "Enter A for alien and B for human" << endl;
        cin >> choice;
        cin.ignore(10000, '\n');
        choice = toupper(choice);//Turn the choice into upper case
        if (choice != 'A' && choice != 'B') {
            cout << "Incorrect choice, enter A or B" << endl; //just send no matching command found or unidentify comma
            continue; // Go back to the main menu
        }

        cout << "Enter the name to search" << endl;
        string Ninput;
        cin >> Ninput;

        if (choice == 'A') {
            alienList.advancedNameSearch(Ninput);
        }
        else if (choice == 'B') {
            humanList.advancedNameSearch(Ninput);
        }

        break;
    }
    case 'G': {
        running = false;
        cout << "Quitting due to user request" << endl;
        break; 
    }
    default: {
        cout << "Incorrect choice, enter A B C D E F or G" << endl;
        continue; // Go back to the main menu
    }
        

    };
    }
    return 0;
}