#include "Room.h"
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
//constructor for room
Room::Room(char* newLabel, char* newDescription){
 label = new char[20];
  strcpy(label,newLabel);
  description = new char[150];
  strcpy(description, newDescription);
}
//cycle through items in room vector and print out the labels of each
void Room::printItems(){
  cout << "Objects here: " << endl;
  for(vector<Item*>::iterator it = items.begin(); it!=items.end(); it++){
    cout << (*it)->getLabel() << "  ";
  }
  cout << endl;
}
//cycle through the map of exits, and print out the key (NORTH,SOUTH, EAST, WEST) of each
void Room::printExits(){
  map<char*,Room*>::iterator it;
  for(it = neighbors.begin(); it != neighbors.end(); it++){
    cout << it->first << "  ";
  }
}
//cycle through the map until the user's exit input matches the key of the iterator, then print out the room stored at that key
Room* Room::getNextRoom(char* direction){
  map<char*,Room*>::iterator it;
  for(it = neighbors.begin(); it != neighbors.end(); it++){
    if(strcmp((it->first),direction)==0){
      return it->second;
    }
  }
  return NULL;
}
//cycle through the vector of items in the room, and return the item that matches the label of the user's input
Item* Room::getItem(char* label){
  for(vector<Item*>::iterator it = items.begin(); it!=items.end(); it++){
    char* itemlabel = (*it)->getLabel();
    if(strcmp(itemlabel,label)==0){
      return (*it);
    }
  }
  return NULL;
}
//cycle through the vector of items in the room and erase the item that matches the inputted label
void Room::removeItem(char* label){
  for(vector<Item*>::iterator it = items.begin(); it!=items.end(); it++){
    char* itemlabel = (*it)->getLabel();
    if(strcmp(itemlabel,label)==0){
      items.erase(it);
      break;
    }
  }
}

//add item to the item vector for the room
void Room::addItem(Item* i){
  items.push_back(i);
}

//return the description of the room
char* Room::getDescription(){
  return description;
}

//return the label of the room
char* Room::getLabel(){
  return label;
}

//add the key and room to the map
void Room::addNeighbor(char* direction, Room* neighbor){
  neighbors.insert({direction,neighbor});
}
