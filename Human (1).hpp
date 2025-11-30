#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "CrewMember.hpp"
#include <iostream>

using namespace std;

namespace HU {
    class Human : public CM::CrewMember {
        public: 
        //Constructor
        Human ();
        Human (const string& fName, const string& lName, int id, float tScore, int mAptitude, string hSector);

        // Getters
        const string& getHomeSector() const;

        // Setters
        void setHomeSector(const string& hSector);

        //Overloading the output operator
        friend ostream& operator <<(ostream& out, const Human& hu);

        //Overriding the output function as requested in project final
        void print() const override;

        private: 
        string homeSector;
    };
}
#endif
