/* room.h
* Defines the Room class for the adventure game.
* Stores the room name, description, and directional exits.
* Elizabeth Cret. 3/30/2026
*/


#ifndef ROOM_H // Prevents this file from being included more than once
#define ROOM_H //this is a header guard.

#include <string>
using namespace std;

class Room{
    private:
    string name;
    string description;

    // Pointers to neighboring rooms and creates a map of the world
    Room* north;
    Room* south;
    Room* east;
    Room* west;

    public:
    //constructors
    Room(); //default constructor
    Room(string n, string d); //overloaded constructor

    //accessors (getters)
    string getName() const;
    string getDescription() const;

    Room* getNorthExit() const;
    Room* getSouthExit() const;
    Room* getEastExit() const;
    Room* getWestExit() const;

    //mutators (setters)
    void setNorth(Room* r);
    void setSouth(Room* r);
    void setEast(Room* r);
    void setWest(Room* r);
    
    //display
    void printInfo() const;
    void printExits() const;

};

#endif //ends ROOM_H