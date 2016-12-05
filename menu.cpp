
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "database.h"
#include "menu.h"

//constructor
menu::menu(){

  database* dab = new database();
  //calls database input to put data from textfile into the vector that database created
  dab->input();
}

//destructor
menu::~menu(){
  delete dab;
}

//calls all other menus and functions 
void menu::mainmenu(){
	std::string file;
  std::string choice;
  bool keepgoing = true;
  //main menu, first thing user sees
  //also keepsgoing until they exit
  while(keepgoing){
    //options outputed for user
    choice = " ";
    std::cout<<"Zipcode Database Main Menu\n\n";
    std::cout<<"Please enter the number next to you choice.\n\n";
    std::cout<<"(1) Search\n";
    std::cout<<"(2) Sort\n";
    std::cout<<"(3) Find Distance\n";
    std::cout<<"(4) Add New Zipcode\n";
    std::cout<<"(5) Display Zipcode\n";
	std::cout<<"(6) Create file of database";
    std::cout<<"(7) Exit\n";
    std::cin>>choice;
	//checks which choice was entered and calls the corresponging function
    if(choice == "1"){dab->searchmethods();}
    else if(choice == "2"){dab->displaysort();}
    else if(choice == "3"){distancemenu();}
    else if(choice == "4"){dab->addzipcode();}
    else if(choice == "5"){displaymenu();}
	else if (choice == "6") {
		std::cout << "Please enter the name you want this text file saved under.\n";
		std::cout << "If you would like to use this ouput file as input for the \n";
		std::cout << "next time you use this program, then name it 'zip_code_database'.\n";
		dab->output(file);}
    else if(choice == "7"){keepgoing = false;}
    else{std::cout<<"Your entry could not be unterstood, please enter an integer between 1 and 6\n";}
  }
 
}

//prompts the user to enter two zipcodes which are put int the finddistance function
void menu::distancemenu(){

  std::string zip1, zip2;
  std::cout<<"Please enter two known zipcodes.\n";
  std::cin>>zip1;
  std::cin>>zip2;
  dab->finddistance(zip1,zip2);

}

//calls display functions in database after user inputs which one they want
void menu::displaymenu(){
  bool keepgoing = true;
  //loops until a valid reesponse is entered
  while(keepgoing){
	//menu user will see
    std::string choice =" ";
    std::cout<<"Display Options\n\n";
    std::cout<<"(1) Display all data for one element\n";
    std::cout<<"(2) Display basic data for many\n";
	std::cout << "(3) Back\n";
    std::cin>>choice;
	//promps the user to enter data the other functions need
    if(choice == "1"){
      std::cout<<"Please enter the number of the zipcode you would like to see.\n";
      std::string number = " ";
      std::cin>>number;
      dab->fulldisplay(number); 
      keepgoing = false;
	}
	else if (choice == "2") {
		dab->partialdisplayzip();
		keepgoing = false;
	}
	else if(choice == "3"){
		keepgoing = false;
    }
    else{std::cout<<"That is not a valid response\n";}

  }
}


