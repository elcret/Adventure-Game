//adventure game part 1
//Elizabeth Cret. 3/30/2026
//Create the Room class and build the world
/*n main.cpp:
o Build the world by creating at least six rooms and connecting the rooms using the exit
pointers (north, south, east, west)
o Create a variable called currentRoom that is a pointer to the currentRoom and set it
to a starting room
o Test your program fully before you move onto input parsing!*/



#include <iostream>
#include <string>
#include "room.h"

using namespace std;

//struct to hold the players command
struct Command{
    string verb; // action (go, look, help)
    string arg;  // direction or extra info (north, south...)
};

// function to parse the player's input into a Command struct
Command parseCommand(string input) {
    Command command;

    int spacePos = input.find(' '); //find where the space is

    if (spacePos == -1) { //if there is no space and only one word was typed
        command.verb = input; //whole input is a verb
        command.arg = ""; //no argument
    }
    else {
        command.verb = input.substr(0, spacePos); //everything before the space is a verb
        command.arg = input.substr(spacePos + 1); //everything after the space is the argument
    }

    return command; //return the filled struct
}

//function to move the player to another room
//takes the current room pointer and updates it if move is still valid
bool move(Room*& currentRoom, string direction){

    //check each direction to see if there is a connected room
    if(direction == "north"){
        if(currentRoom->getNorthExit() != nullptr){
            currentRoom = currentRoom->getNorthExit();
            return true;
        }
        else{
            cout << "You can't go that way!" << endl;
            return false;
        }
    }
    else if(direction == "south"){
        if(currentRoom->getSouthExit() != nullptr){
            currentRoom = currentRoom->getSouthExit();
            return true;
        }
        else{
            cout << "You can't go that way!" << endl;
            return false;
        }
    }
    else if(direction == "east"){
        if(currentRoom->getEastExit() != nullptr){
            currentRoom = currentRoom->getEastExit();
            return true;
        }
        else{
            cout << "You can't go that way!" << endl;
            return false;
        }
    }
    else if(direction == "west"){
        if(currentRoom->getWestExit() != nullptr){
            currentRoom = currentRoom->getWestExit();
            return true;
        }
        else{ 
            cout << "You can't go that way!" << endl;
            return false;
        }
    }
    else{ //input validation
        cout << "Invalid direction. Please enter north, south, east, or west." << endl;
        return false;
    }
}


int main(){
    //create 6 rooms
    //they are created when main() runs and are destroyed when main() ends, so we don't need to worry about memory management

    Room coralReef("Coral Reef",
    "You are surrounded by colorful coral and tropical fish. The water is warm and clear.");

    Room whiteSands("White Sands", "Soft white sand covers the ocean floor. Shells sparkle around you. The water is soft blue and calm.");

    Room sharkTerritory("Shark Territory", "The water is murky and dark. You can see the silhouette of a large shark in the distance. You feel a chill run down your spine.");

    Room pearlPalace("Pearl Palace", "You see a magnificent palace made of shimmering pearls. The walls glisten and the floors are smooth. You feel like royalty in this underwater kingdom.");

    Room jellyfishGarden("Jellyfish Garden", "You are surrounded by glowing jellyfish of all shapes and sizes. They light up the water around you, creating a magical atmosphere. You feel like you're in a dream.");

    Room shipWreck("Shipwreck", "You see the remains of a sunken ship. The wood is old and covered in algae. You can see treasure chests and old artifacts scattered around. You wonder what secrets this ship holds but the entrance is blocked by debris.");


//---------------------------------------------------------
//map layout

// Coral Reef >>> White Sands >>> Shark Territory
//        |                |                |
// Jellyfish Garden >>> Pearl Palace >>> Shipwreck

//-----------------------------------------------------------

//connect the rooms together by setting the pointers to the neighboring rooms   
//Top row (Coral Reef, White Sands, Shark Territory)
    coralReef.setEast(&whiteSands);
    whiteSands.setWest(&coralReef);

    whiteSands.setEast(&sharkTerritory);
    sharkTerritory.setWest(&whiteSands);

    //Bottom row (Jellyfish Garden, Pearl Palace, Shipwreck)
    jellyfishGarden.setEast(&pearlPalace);
    pearlPalace.setWest(&jellyfishGarden);

    pearlPalace.setEast(&shipWreck);
    shipWreck.setWest(&pearlPalace);

    //Vertical connections
    coralReef.setSouth(&jellyfishGarden);
    jellyfishGarden.setNorth(&coralReef);

    whiteSands.setSouth(&pearlPalace);
    pearlPalace.setNorth(&whiteSands);

    sharkTerritory.setSouth(&shipWreck);
    shipWreck.setNorth(&sharkTerritory);

    //set starting room
    //pointer to track the current room the player is in
    Room* currentRoom = &coralReef;

    // intro message
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "        ><(((('>        ><(((('>        ><(((('>        " << endl;
    cout << "   ><(((('>        ><(((('>        ><(((('>        ><(((('>" << endl;
    cout << "        ><(((('>        ><(((('>        ><(((('>        " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << endl;
    cout << "           Welcome to the Underwater Adventure Game!" << endl;
    cout << "      Grab your mermaid tail and dive into the ocean!" << endl;
    cout << "         Explore, discover, and enjoy the journey!" << endl;

    cout << endl;
    cout << "---------------------- Commands ----------------------" << endl;
    cout << "  look   - view your current location" << endl;
    cout << "  go ___ - move north, south, east, or west" << endl;
    cout << "  help   - show commands again" << endl;
    cout << "  quit   - exit the game" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << endl;
    cout << "              Your adventure begins here..." << endl;
    currentRoom->printInfo();
    currentRoom->printExits();
    cout << endl;

string input; //variable to hold the player's input
Command cmd; //variable to hold the parsed command

while (true) { //game loop

    cout << ">"; //prompt for input
    getline(cin, input); //get full line from user

    cmd = parseCommand(input); //break input into parts

    //show room info
    if (cmd.verb == "look") {
        currentRoom->printInfo();
        currentRoom->printExits();
        cout << endl;
    }
    //show help menu
    else if (cmd.verb == "help") {
        cout << endl;
        cout << "==================== HELP MENU ====================" << endl;
        cout << " look   - view current room" << endl;
        cout << " go ___ - move north, south, east, or west" << endl;
        cout << " help   - show commands" << endl;
        cout << " quit   - exit the game" << endl;
        cout << "===================================================" << endl;
        currentRoom->printExits();
        cout << endl;
    }
    //move command
    else if (cmd.verb == "go") {
        if (move(currentRoom, cmd.arg)) {
            cout << endl;
            currentRoom->printInfo();
            currentRoom->printExits();
            cout << endl;
        }
        else if (cmd.arg != "north" && cmd.arg != "south" &&
                 cmd.arg != "east" && cmd.arg != "west") {
            cout << "Invalid command." << endl;
        }
    }
    //quit the game
    else if (cmd.verb == "quit") {
        cout << "Thanks for playing! Goodbye!" << endl;
        break;
    }
    //anything else is invalid
    else {
        cout << "Invalid command." << endl;
    }
}

    return 0;
}
