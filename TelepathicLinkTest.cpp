#include "TelepathicLinkTest.hpp"

namespace TLT{
    //Constructor
    TelepathicLinkTest::TelepathicLinkTest()
        :signalStrength(0), cognitiveLink(0), empathyOverlay(0), cognitiveResistance(0), total(0)
        {}

    TelepathicLinkTest::TelepathicLinkTest(int sigStrength, int cogLink, int empOveral, int cogRes, int tot) 
        {  
            if (cogRes < 0 || cogRes > 10) {
                cout << "TelepathicLinkTest.cpp Error: Cognitive resistance has to be between 0 and 10. Setting to 0 by default." << endl;
                cogRes = 0;
            }
            signalStrength = sigStrength;
            cognitiveLink = cogLink;
            empathyOverlay = empOveral;
            cognitiveResistance = cogRes;
            total = tot; 
        }

    //Getter
    int TelepathicLinkTest::getSigStrength() const
        {
            return signalStrength;
        }
    int TelepathicLinkTest::getCogLink() const
        {
            return cognitiveLink;
        }
    int TelepathicLinkTest::getEmpOveral() const
        {
            return empathyOverlay;
        }
    int TelepathicLinkTest::getCogRes() const
        {
            return cognitiveResistance;
        }
    int TelepathicLinkTest::getTot() const
        {
            return total; 
        }

    //Setter
    void TelepathicLinkTest::setSigStrength(int sigStrength)
        {
            signalStrength = sigStrength; 
        }
    void TelepathicLinkTest::setCogLink(int cogLink)
        {
            cognitiveLink = cogLink;
        }
    void TelepathicLinkTest::setEmpOveral(int empOveral)
        {
            empathyOverlay = empOveral;
        }
    void TelepathicLinkTest::setCogRes(int cogRes)
        {
            cognitiveResistance = cogRes;
        }
    void TelepathicLinkTest::setTot(int tot)
        {
            total = tot;
        }

    //Added in project final
    std::ostream& operator<<(std::ostream& os, const TelepathicLinkTest& tlt) {
        os << " signal strength: " << tlt.getSigStrength() 
        << " cognitive link: " << tlt.getCogLink()
        << " empathy overlay: " << tlt.getEmpOveral()
        << " cognitive resistance: " << tlt.getCogRes()
        << " total: " << tlt.getTot() << endl;
        return os;
    }
};
