/* room.cpp
* Implements the Room class functions.
* Defines constructors, getters, setters, and print functions.
* Elizabeth Cret. 3/30/2026
*/


#include "room.h"
#include <iostream>
using namespace std;

const string line = "======================================================";

//default constructor
Room::Room(){ //creates an empty room with no name, description, or exits
    name = "";
    description = "";

    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
}

//overloaded constructor
//now we can create a room with a name and description
Room::Room(string n, string d){
    name = n;
    description = d;

    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
}

//accessors (getters)
string Room::getName() const{
    return name;
}

string Room::getDescription() const{
    return description;
}

Room* Room::getNorthExit() const{
    return north;
}

Room* Room::getSouthExit() const{
    return south;
}

Room* Room::getEastExit() const{
    return east;
}

Room* Room::getWestExit() const{
    return west;
}

//mutators (setters)
//these functions connnect the rooms together by setting the pointers to the neighboring rooms
void Room :: setNorth(Room* r){
    north = r;
}

void Room :: setSouth(Room* r){
    south = r;
}

void Room :: setEast(Room* r){
    east = r;
}

void Room :: setWest(Room* r){
    west = r;
}

//print room and the description when player enters the room
void Room::printInfo() const {
    cout << endl;
    cout << line << endl;
    cout << "                " << name << endl;
    cout << line << endl;
    cout << endl;
    cout << "  Description:\n";
    cout << "  " << description << endl;
}
//print the exits
//only prints directions that are not nullptr (there is a room in that direction)
void Room::printExits() const {
    cout << endl;
    cout << "~~~~~~~~~~~~~~ Where you can swim ~~~~~~~~~~~~~~~~~~~" << endl;

    if (north != nullptr) cout << "   ^  North" << endl;
    if (south != nullptr) cout << "   v  South" << endl;
    if (east != nullptr) cout << "   >  East" << endl;
    if (west != nullptr) cout << "   <  West" << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
}