#include <iostream>
#include "Room.h"
#include "Item.h"
#include <vector>
#include <cstring>

using namespace std;

//method prototypes
void printRoom(Room* toPrint, vector<Item*> inventoryy);
void addItem(Room* currentRoom, char* itemlistt, vector<Item*> &inventoryy);
void printInventory(vector<Item*> inventory);
void dropItem(char* item, Room* currentRoom, vector<Item*> &inventory);

int main(){
  //defining the chars to pass as north, south, east and west
  char SOUTH[10] =  "SOUTH";
  char NORTH[10] = "NORTH";
  char WEST[10] = "WEST";
  char EAST[10] = "EAST";
  //defining vectors of item pointers and room pointers
  vector<Item*> inventory;
  vector<Room*> rooms;

  //creating all room pointers and adding items to some rooms
  char item[20] = "";
  char label[20] = "lab";
  char description[150] = "You are in the computer lab, the whir of computers surround you. Wait did that robot just move by itself?";
  Room* lab = new Room(label, description);

  strcpy(label,"bathroom");
  strcpy(description ,"You are in the bathroom. Unlike the school one, this one smells tolerable. Is that lavender?");
  Room* bathroom = new Room(label,description);
  strcpy(item,"SOAP");
  Item* soap = new Item(item);
  bathroom->addItem(soap);
  
  strcpy(label,"pool");
  strcpy(description ,"You have entered the pool room. Woah the floor is slippery, don't fall in!");
  Room* pool = new Room(label,description);
  
  strcpy(label,"hot tub");
  strcpy(description ,"You are in the hot tub room. It's so hot in here, and the steam is so thick you can barely see!");
  Room* hottub = new Room(label,description);
  
  strcpy(label,"roller coaster");
  strcpy(description ,"You are in the roller coaster room. Wow, could the rooms get any weirder? Wait is that kid falling?");
  Room* rollercoaster = new Room(label,description);
  
  strcpy(label,"animal farm");
  strcpy(description ,"You are in the animal farm. Is it just me or is that bull coming towards you a little too fast...");
  Room* animalfarm = new Room(label,description);
  
  strcpy(label,"ball pit");
  strcpy(description ,"You've fallen into the ball pit. Getting out will require immense effort. Who knew this would be so difficult?");
  Room* ballpit = new Room(label,description);
  strcpy(item,"BALL");
  Item* ball = new Item(item);
  ballpit->addItem(ball);
  
  strcpy(label,"cafeteria");
  strcpy(description ,"You are in the cafeteria. Remnants of food fights still stain the walls.");
  Room* cafeteria = new Room(label,description);
  
  strcpy(label,"ice cream");
  strcpy(description ,"You are in the ice cream shop. Ooh birthday cake, your favorite!");
  Room* icecream = new Room(label,description);
  
  strcpy(label,"indoor beach");
  strcpy(description ,"You are in the indoor beach. In case you don't know what that is, it's like a beach, but indoors");
  Room* indoorbeach = new Room(label,description);
  strcpy(item,"SHOVEL");
  Item* shovel = new Item(item);
  indoorbeach->addItem(shovel);
  
  strcpy(label,"shaved ice");
  strcpy(description ,"You are at the shaved ice shop! Who knew strawberry and root beer would go together so well!");
  Room* shavedice = new Room(label,description);
  
  strcpy(label,"kitchen");
  strcpy(description ,"You are in the kitchen. There's no way that lump of tasteless flour becomes bread.");
  Room* kitchen = new Room(label,description);
  strcpy(item,"KNIFE");
  Item* knife = new Item(item);
  kitchen->addItem(knife);
  
  strcpy(label,"tree house");
  strcpy(description ,"You are in the tree house! so. high. above. the. ground. Don't fall!");
  Room* treehouse = new Room(label,description);
  
  strcpy(label,"puppy room");
  strcpy(description ,"You are in the puppy room. You want to leave, but how can anyone say no to those eyes?");
  Room* puppyroom = new Room(label,description);
  strcpy(item,"PUPPY");
  Item* puppy = new Item(item);
  puppyroom->addItem(puppy);
  
  strcpy(label,"trampoline");
  strcpy(description ,"You are in the trampoline room. Wow it feels like you're on the moon! Watch out for the ceiling!");
  Room* trampoline = new Room(label,description);
  
  strcpy(label,"theater");
  strcpy(description ,"You are in the indoor theater. Your shoes are probably going to have popcorn all over them for the next month or so.");
  Room* theater = new Room(label,description);
  
  strcpy(label,"garden");
  strcpy(description ,"You are in the garden! You trip and fall into a rose bush. Wow what a nice smell! Ouch, you forget about the thorns.");
  Room* garden = new Room(label,description);
  strcpy(item,"FLOWER");
  Item* flower = new Item(item);
  garden->addItem(flower);
  
  strcpy(label,"driveway");
  strcpy(description ,"You have made it to the driveway. Finally, you're free. Congratulations on completing ZUUL the adventure game!");
  Room* driveway = new Room(label,description);

  //mapping out the north, south, east, and/or west exits of each room
  lab->addNeighbor(NORTH, rollercoaster);
  lab->addNeighbor(EAST, bathroom);
  bathroom->addNeighbor(WEST, lab);
  bathroom->addNeighbor(NORTH, pool);
  pool->addNeighbor(NORTH, ballpit);
  pool->addNeighbor(SOUTH, bathroom);
  pool->addNeighbor(EAST, hottub);
  pool->addNeighbor(WEST, rollercoaster);
  hottub->addNeighbor(WEST,pool);
  rollercoaster->addNeighbor(NORTH,cafeteria);
  rollercoaster->addNeighbor(SOUTH, lab);
  rollercoaster->addNeighbor(EAST, pool);
  rollercoaster->addNeighbor(WEST, animalfarm);
  ballpit->addNeighbor(NORTH,puppyroom);
  ballpit->addNeighbor(SOUTH, pool);
  ballpit->addNeighbor(WEST, cafeteria);
  puppyroom->addNeighbor(SOUTH,ballpit);
  puppyroom->addNeighbor(EAST, trampoline);
  puppyroom->addNeighbor(WEST,treehouse);
  trampoline->addNeighbor(NORTH, theater);
  trampoline->addNeighbor(WEST, puppyroom);
  theater->addNeighbor(SOUTH, trampoline);
  cafeteria->addNeighbor(NORTH,treehouse);
  cafeteria->addNeighbor(SOUTH, rollercoaster);
  cafeteria->addNeighbor(EAST, ballpit);
  cafeteria->addNeighbor(WEST, icecream);
  treehouse->addNeighbor(NORTH, garden);
  treehouse->addNeighbor(SOUTH, cafeteria);
  treehouse->addNeighbor(EAST, puppyroom);
  garden->addNeighbor(SOUTH, treehouse);
  animalfarm->addNeighbor(NORTH, icecream);
  animalfarm->addNeighbor(EAST, rollercoaster);
  icecream->addNeighbor(EAST, cafeteria);
  icecream->addNeighbor(WEST, indoorbeach);
  icecream->addNeighbor(SOUTH, animalfarm);
  indoorbeach->addNeighbor(NORTH, kitchen);
  indoorbeach->addNeighbor(EAST, icecream);
  indoorbeach->addNeighbor(WEST, shavedice);
  shavedice->addNeighbor(EAST, indoorbeach);
  kitchen->addNeighbor(NORTH, driveway);
  kitchen->addNeighbor(SOUTH, indoorbeach);

  //adding all rooms to the room vector
  rooms.push_back(lab);
  rooms.push_back(bathroom);
  rooms.push_back(pool);
  rooms.push_back(hottub);
  rooms.push_back(rollercoaster);
  rooms.push_back(animalfarm);
  rooms.push_back(ballpit);
  rooms.push_back(cafeteria);
  rooms.push_back(icecream);
  rooms.push_back(indoorbeach);
  rooms.push_back(shavedice);
  rooms.push_back(kitchen);
  rooms.push_back(treehouse);
  rooms.push_back(puppyroom);
  rooms.push_back(trampoline);
  rooms.push_back(theater);
  rooms.push_back(garden);
  rooms.push_back(driveway);

  
  Room* currentRoom = lab;
  bool won = false;
  char input[10];
  //intro print
  cout << "Welcome to ZUUL, the adventure game! Every turn, you can choose to go to a room, drop an item, pick up an item, or quit! Try your best to make your way out! Good luck."<< endl;
  //game cycle
  while(!won){
    //print out the description, items, exits, and inventory before every user prompt
    cout << endl;
    printRoom(currentRoom,inventory);
    //if user reached winning condition stop the program
    if(strcmp(currentRoom->getLabel(),"driveway")==0){
      break;
    }
    cout << "Type go, drop, pick up, or quit!" << endl;
    cin.get(input,10);
    cin.get();
    //if user entered quit, then stop the program
    if(input[0]=='q' || input[0]=='Q'){
      break;
    }
    //if user typed go, get user input for which exit, and then call getNextRoom method in Room.cpp
    else if(input[0]=='g' || input[0]=='G'){
      char exit[10];
      cout << "type which exit you would like to use" << endl;
      cin.get(exit,10);
      cin.get();
      if(currentRoom->getNextRoom(exit)!=NULL){
	currentRoom = currentRoom->getNextRoom(exit);
      }
      else{
	cout << "this is not a valid exit" << endl;
      }
    }
    //if user typed pick up, ask them which item they want to pick up, then call addItem method
    else if(input[0]=='p' || input[0]=='P'){
      char itemlabel[10];
      cout << "which of the above items would you like to pick up" << endl;
      cin.get(itemlabel,10);
      cin.get();
      addItem(currentRoom, itemlabel,inventory);
    }
    //if user types drop, ask them which item they want to drop, then call dropItem method
    else if(input[0]=='d' || input[0]=='D'){
      char itemlabel[10];
      cout << "which of the items in your inventory would you like to drop" << endl;
      cin.get(itemlabel,10);
      cin.get();
      dropItem(itemlabel,currentRoom, inventory);
    }
  }
  
  return 0;

}

//get the item in the room that matches user input and add it to inventory
//then remove the item from the room
void addItem(Room* currentRoom, char* itemlabell, vector<Item*> &inventoryy){
  if(currentRoom->getItem(itemlabell)!=NULL){
    inventoryy.push_back(currentRoom->getItem(itemlabell));
    currentRoom->removeItem(itemlabell);
  }
  else{
    cout << "sorry this room doesn't have the item you are requesting" << endl;
  }
}

//print the description of the room, the items, exits, and inventory
void printRoom(Room* toPrint, vector<Item*> inventoryy){

  char print[150];
  strcpy(print,(toPrint->getDescription()));
  cout << endl;
  cout << endl;
  cout << print << endl;
  toPrint->printItems();
  cout << "There are exits:" << endl;
  toPrint->printExits();
  cout << endl;
  cout << "Your inventory has:" << endl;
  printInventory(inventoryy);
  cout << endl;
  cout << endl;
}

//go through all the items in the inventory and print out the labels
void printInventory(vector<Item*> inventory){
  for(vector<Item*>::iterator it=inventory.begin(); it!=inventory.end(); it++){
    cout << (*it)->getLabel() << "  ";
  }
}

//cycle through the inventory and add the item with the matching label to the current room
//after, cycle through the inventory again and erase the item with the matching label from the inventory
void dropItem(char* item, Room* currentRoom, vector<Item*> &inventory){
  for(vector<Item*>::iterator it=inventory.begin(); it!=inventory.end(); it++){
    char* currentLabel = (*it)->getLabel();
    if(strcmp(item,currentLabel)==0){
      currentRoom->addItem(*it);
      break;
    }
  }
  for(vector<Item*>::iterator it=inventory.begin(); it!=inventory.end(); it++){
    char* currentLabel = (*it)->getLabel();
    if(strcmp(item,currentLabel)==0){
      inventory.erase(it);
      break;
    }
  }
}
