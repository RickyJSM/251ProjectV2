#ifndef  TELEPATHICLINKTEST_HPP
#define TELEPATHICLINKTEST_HPP
#include "CrewMember.hpp"

using namespace std;

namespace TLT {
    class TelepathicLinkTest {
        public:

        // Constructor
            TelepathicLinkTest();
            TelepathicLinkTest(int sigStrength, int cogLink, int empOveral, int cogRes, int tot); 

        //Getters
            int getSigStrength() const;
            int getCogLink() const;
            int getEmpOveral() const;
            int getCogRes() const; 
            int getTot() const;


        //Mutators
            void setSigStrength(int sigStrength);
            void setCogLink(int cogLink);
            void setEmpOveral(int empOveral);
            void setCogRes(int cogRes); 
            void setTot(int tot);


            friend std::ostream& operator<<(std::ostream& os, const TelepathicLinkTest& tlt);

        private:
            int signalStrength;
            int cognitiveLink;
            int empathyOverlay;
            int cognitiveResistance;
            int total;
    };
}

#endif