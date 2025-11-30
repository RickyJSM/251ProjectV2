#include "Alien.hpp"

namespace AL {
    Alien::Alien() : CM::CrewMember(), homeWorld(""), TeleLinkTest() {};

    Alien::Alien(const string& fName, const string& lName, int id, float tScore, int mAptitude, const std::string& hWorld,
            int sStrength, int cLink, int eOveraly, int cResistance, int tot)
        : CrewMember(fName, lName, tScore, mAptitude, id), homeWorld(hWorld), TeleLinkTest(sStrength, cLink, eOveraly, cResistance, tot) {};

    // Getters
    std::string Alien::getHomeWorld() const {
        return homeWorld;
    }

    TLT::TelepathicLinkTest Alien::getTeleLinkTest() const {
        return TeleLinkTest;
    }

    // setters
    void Alien::setHomeWorld(const std::string& Hworld) {
        homeWorld = Hworld;
    }

    void Alien::setTeleLinkTest(const TLT::TelepathicLinkTest& tLinkTest) {
        TeleLinkTest = tLinkTest;
    }

    //Output
    ostream& operator<<(ostream& out, const Alien& AL) {
        out << "ID: " << AL.getID() << ", "
           << "Name: " << AL.getFName() << " " << AL.getLName() << ", "
           << "Training Score: " << AL.getTScore() << ", "
           << "Mission Aptitude: " << AL.getMAptitude() << ", "
           << "Home World: " << AL.getHomeWorld() << ", "
           << "Signal Strength: " << AL.getTeleLinkTest().getSigStrength() << ", "
           << "Cognitive Link: " << AL.getTeleLinkTest().getCogLink() << ", "
           << "Empathy Overaly: " << AL.getTeleLinkTest().getEmpOveral() << ", "
           << "Cognitive Resistance: " << AL.getTeleLinkTest().getCogRes() << ", "
           << "Total: " << AL.getTeleLinkTest().getTot() << endl;
        return out;
    }

    //Project 
    void Alien::print() const {
        CM::CrewMember::print();
        cout << " home world: " << homeWorld
        << " " << TeleLinkTest;
    }
}
