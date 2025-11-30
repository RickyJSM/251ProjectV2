#ifndef CREWMEMBER_HPP
#define CREWMEMBER_HPP
#include "TelepathicLinkTest.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace CM {
    class CrewMember {
        public:
        
    //Constructor
        CrewMember();
        CrewMember(string fName, string lName, float tScore, int mAptitude, int id);
    
    //Getters
        string getFName() const;
        string getLName() const;
        float getTScore() const;
        int getMAptitude() const; 
        int getID() const;


    //Mutators
        void setFName(string fName);
        void setLName(string lName);
        void setTScore(float tScore);
        void setMAptitude(int mAptitude);
        void setID(int id);

    //friend functions 
        friend int compareTrainingScore(const CrewMember& a, const CrewMember& b);
        friend int compareMissionAptitude(const CrewMember& a, const CrewMember& b);
        friend int compareFirstName(const CrewMember& a, const CrewMember& b);
        friend int compareLastName(const CrewMember& a, const CrewMember& b);

    //Virtual print function as requested in project final
        virtual void print() const;

        private:
        string firstName;
        string lastName;
        float trainingScore;
        int missionAptitude;
        int ID = 25220000;
        static int nextID;
    };
}

#endif
