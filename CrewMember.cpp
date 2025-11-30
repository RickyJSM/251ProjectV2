#include "CrewMember.hpp"

namespace CM {
    int CrewMember::nextID = 25220000;
    
    //Constructors
    CrewMember::CrewMember() 
        : firstName(""), lastName(""), trainingScore(0.0), missionAptitude(0), ID(nextID++)
        {}

    CrewMember::CrewMember(string fName, string lName, float tScore, int mAptitude, int id)
        {
            if (tScore < 0 || tScore > 4.3) {
                cout << "CrewMember.cpp Error: Training Score has to be between 0 and 4.3. Setting to 0 by default." << endl;
                tScore = 0;
            }
            if (mAptitude < 0 || mAptitude > 100) {
                cout << "CrewMember.cpp Error: Mission Aptitude has to be between 0 and 100. Setting to 0 by default." << endl;
                mAptitude = 0;
            }

            firstName = fName;
            lastName = lName;
            trainingScore = tScore;
            missionAptitude = mAptitude;
            ID = id;
        }

    //Getters
    string CrewMember::getFName() const 
        {
            return firstName;
        }
    string CrewMember::getLName() const
        {
            return lastName;
        }
    float CrewMember::getTScore() const
        {
            return trainingScore;
        }
    int CrewMember::getMAptitude() const
        {
            return missionAptitude;
        }
    int CrewMember::getID() const
        {   
            return ID;
        }

    //Setter
    void CrewMember::setFName(string fName)
        {
            firstName = fName;
        }
    void CrewMember::setLName(string lName)
        {
            lastName = lName;
        }
    void CrewMember::setTScore(float tScore)
        {
            trainingScore = tScore;
        }
    void CrewMember::setMAptitude(int mAptitude) 
        {
            missionAptitude = mAptitude;
        }
    void CrewMember::setID(int id)
        {
            ID = id;
        }

    //Comparators
    int compareTrainingScore(const CrewMember& a, const CrewMember& b){
        if (a.getTScore() < b.getTScore()) return -1;
        else if (a.getTScore() > b.getTScore()) return 1;
        else return 0;
    }
    int compareMissionAptitude(const CrewMember& a, const CrewMember& b){
        if (a.getMAptitude() < b.getMAptitude()) return -1;
        else if (a.getMAptitude() > b.getMAptitude()) return 1;
        else return 0;
    }
    int compareFirstName(const CrewMember& a, const CrewMember& b){
        if (a.getFName() < b.getFName()) return -1;
        else if (a.getFName() > b.getFName()) return 1;
        else return 0;
    }
    int compareLastName(const CrewMember& a, const CrewMember& b){
        if (a.getLName() < b.getLName()) return -1;
        else if (a.getLName() > b.getLName()) return 1;
        else return 0;
    }

    //Virtual print function as requested in project final
    void CrewMember::print() const {
        cout << "FirstName: " << firstName 
        << " last name: " << lastName
        << " training score: " << trainingScore
        << " mission aptitude: " << missionAptitude
        << " ID: " << nextID;
    };
}