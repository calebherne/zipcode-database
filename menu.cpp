
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "database.h"
#include "menu.h"

menu::menu(){
  database* dab = new database();
  //dab->input(); //wont work until I fix input
}

menu::~menu(){
  delete dab;
}

   
void menu::mainmenu(){
  
  std::string choice;
  bool keepgoing = true;
  while(keepgoing){
    choice = " ";
    std::cout<<"Zipcode Database Main Menu\n\n";
    std::cout<<"Please enter the number next to you choice.\n\n";
    std::cout<<"(1) Search\n";
    std::cout<<"(2) Sort\n";
    std::cout<<"(3) Find Distance\n";
    std::cout<<"(4) Add New Zipcode\n";
    std::cout<<"(5) Display Zipcode\n";
    std::cout<<"(6) Exit\n";
    std::cin>>choice;
    if(choice == "1"){dab->searchmethods();}
    else if(choice == "2"){dab->displaysort();}
    else if(choice == "3"){distancemenu();}
    else if(choice == "4"){dab->addzipcode();}
    else if(choice == "5"){displaymenu();}
    else if(choice == "6"){keepgoing = false;}
    else{std::cout<<"Your entry could not be unterstood, please enter an integer between 1 and 6\n";}
  }
}

void menu::distancemenu(){

  std::string zip1, zip2;
  std::cout<<"Please enter two known zipcodes.\n";
  std::cin>>zip1;
  std::cin>>zip2;
  dab->finddistance(zip1,zip2);

}

void menu::displaymenu(){
  bool keepgoing = true;
  while(keepgoing){
    std::string choice =" ";
    std::cout<<"Display Options\n\n";
    std::cout<<"(1) Display all data for one element\n";
    std::cout<<"(2) Display basic data for many\n";
    std::cin>>choice;
    if(choice == "1"){
      std::cout<<"Please enter the number of the zipcode you would like to see.\n";
      std::string number = " ";
      std::cin>>number;
      dab->fulldisplay(number); 
      keepgoing = false;
    }else if(choice == "2"){
      dab->partialdisplayzip();
      keepgoing = false;
      }
    else{std::cout<<"That is not a valid response\n";}

  }
}


