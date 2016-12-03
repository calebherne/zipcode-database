
#include "database.h"
#ifndef MENU_H_EXISTS
#define MENU_H_EXISTS

class menu{

  privat:
    database *dab;
  public:
    menu();
    ~menu();
    void mainmenu();
    void displaymenu();
    void distancemenu(); 

};

#endif
