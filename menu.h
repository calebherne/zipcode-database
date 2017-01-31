
#include "database.h"
#ifndef MENU_H_EXISTS
#define MENU_H_EXISTS

//displays menus for the user and creates instances of all the other objects
class menu{
  //private variables
  private:
	//only makes a database since it will create a vector of zipcodes
    database dab;

  //public functions
  public:
	//constructor
    menu();
	//destructor
    //~menu();
	//one menu to rule them all
    void mainmenu();
	//used to call display functions from database
    void displaymenu();
	//calls distance funtion from database
    void distancemenu(); 

};

#endif
