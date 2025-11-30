#ifndef DATAINPUT_HPP
#define DATAINPUT_HPP
#include <vector>
#include <sstream>
#include <fstream>
#include "Human.hpp"
#include "Alien.hpp"
#include "LinkedList.hpp"

    //For insensitive string comparison
    bool compareStr(const string& str1, const string& str2);

    //Main Function of this file
    void loadFile(ifstream& alienFile, linkedList<AL::Alien>& alienList,
            ifstream& humanFile, linkedList<HU::Human>& humanList);

    //Functions that will be used inside the main function
    bool loadHuman(string& line, HU::Human& human);
    bool loadAlien(string& line, AL::Alien& alien);
#endif