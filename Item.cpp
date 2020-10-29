#include "Item.h"
#include <cstring>

//constructor for item
Item::Item(char* newLabel){
  label = new char[20];
  strcpy(label,newLabel);
}

//return label of the item
char* Item::getLabel(){
  return label;
}
