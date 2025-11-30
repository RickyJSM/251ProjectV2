#include "DataInput.hpp"

bool compareStr(const string& str1, const string& str2) { //Compares strings insensitively
    if (str1.length() != str2.length()) {
        return false;
    }
    for (int i = 0; i < str1.length(); i++) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
};

bool loadHuman(string& line, HU::Human& human)
    {
        istringstream lineStream(line);
        string fName;
        string lName;
        string sector;
        float tScore;
        int mAptitude;

        if (!(lineStream >> fName >> lName >> sector >> tScore >> mAptitude)) {
            cout << "DataInput.cpp Error: There are missing input fields" << endl;
            return false;
        };

        //Error checking starts here
        try
        {
            if (!(compareStr(sector, "Alpha") || compareStr(sector, "Beta") || compareStr(sector, "Delta") 
            || compareStr(sector, "Sigma") || compareStr(sector, "Omega") || compareStr(sector, "Zeta"))) {
                if (compareStr(sector, "Bata")) {
                    cout << "DataInput.cpp error: You entered " << sector << " instead of Beta" << endl;
                    sector = "Beta";
                }
                else {
                    throw ("Invalid home sector: " + sector);
                }
            }
            if (tScore < 0 || tScore > 4.3) {
                throw ("Training score " + to_string(tScore) + " is out of range");
            }
            if (mAptitude < 0 || mAptitude > 100) {
                throw ("Mission aptitude " + to_string(mAptitude) + " is out of range");
            }
        }
        catch (string error)
        {
            cout << error << endl;
            return false;
        }

        human.setFName(fName);
        human.setLName(lName);
        human.setHomeSector(sector);
        human.setTScore(tScore);
        human.setMAptitude(mAptitude);

        return true;
    }

bool loadAlien(string& line, AL::Alien& alien)
    {
        istringstream lineStream(line);
        string fName;
        string lName;
        string hWorld;
        float tScore;
        int mAptitude;
        int sStrength;
        int cLink;
        int eOverlay;
        int cRes;
        int tot;
        
        if 
        (!(lineStream >> fName >> lName >> hWorld >> tScore 
            >> mAptitude >> sStrength >> cLink >> eOverlay >> cRes >> tot)) {
            cout << "DataInput.cpp Error: There are missing input fields" << endl;
            return false;
        };

        //Error checking starts here
        try
        {
            if (!(compareStr(hWorld, "Altair") || compareStr(hWorld, "Eidolon") || compareStr(hWorld, "Lyra") 
            || compareStr(hWorld, "Mira") || compareStr(hWorld, "Novera") || compareStr(hWorld, "Orion")
            || compareStr(hWorld, "Talos") || compareStr(hWorld, "Trask") || compareStr(hWorld, "Vulcar") 
            || compareStr(hWorld, "Zephon"))) {
                throw ("Invalid home world: " + hWorld);
            }
            if (tScore < 0 || tScore > 4.3) {
                throw ("Training score " + to_string(tScore) + " is out of range");
            }
            if (mAptitude < 0 || mAptitude > 100) {
                throw ("Mission aptitude " + to_string(mAptitude) + " is out of range");
            }
            if (cRes < 0 || cRes > 10) {
                throw ("Cognitive resistance " + to_string(cRes) + " is out of range");
            }
        }
        catch (string error)
        {
            cout << error << endl;
            return false;
        }

        alien.setFName(fName);
        alien.setLName(lName);
        alien.setHomeWorld(hWorld);
        alien.setTScore(tScore);
        alien.setMAptitude(mAptitude);

        TLT::TelepathicLinkTest te = TLT::TelepathicLinkTest(sStrength, cLink, eOverlay, cRes, tot);
        
        alien.setTeleLinkTest(te);
        return true;
    }

void loadFile(ifstream& alienFile, linkedList<AL::Alien>& alienList,
             ifstream& humanFile, linkedList<HU::Human>& humanList)
    {   
        //Checking if the files are open
        if (alienFile.fail()) {
            std::cout << "DataInput.cpp: Error opening alien file." << std::endl;
            exit(1);
        }
        if (humanFile.fail()) {
            std::cout << "DataInput.cpp: Error opening human file." << std::endl;
            exit(1);
        }

        // Loading Alien File
        std::string line;
        while (getline(alienFile, line)) {
            AL::Alien alienI;
            if (loadAlien(line, alienI)) {
                alienList.insertElement(alienI);
            }
        }

        // Loading Human File
        while (getline(humanFile, line)) {
            HU::Human humanI;
            if (loadHuman(line, humanI)) {
                humanList.insertElement(humanI);
            }
        }
    }