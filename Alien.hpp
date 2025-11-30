#ifndef ALIEN_HPP
#define ALIEN_HPP
#include "CrewMember.hpp"
#include "TelepathicLinkTest.hpp"
#include <iostream>
#include <vector> 

namespace AL {
    class Alien : public CM::CrewMember {
        public: 
            //Constructor
            Alien();
            Alien(const string& fName, const string& lName, int id, float tScore, int mAptitude, const std::string& hWorld,
            int sStrength, int cLink, int eOveraly, int cResistance, int tot);

            //Accessors
            std::string getHomeWorld() const;

            TLT::TelepathicLinkTest getTeleLinkTest() const;

            //Mutators
            void setHomeWorld(const std::string& Hworld);

            void setTeleLinkTest(const TLT::TelepathicLinkTest& tLinkTest);

            void print() const override;

        private: 
            std::string homeWorld;
            TLT::TelepathicLinkTest TeleLinkTest; 
    };

    std::ostream& operator<<(std::ostream& out, const Alien& alien);
}
#endif
