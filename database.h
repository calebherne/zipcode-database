
#include "zipcode.h"
#include <vector>
#ifndef DATABASE_H_EXISTS
#define DATABASE_H_EXISTS

//database header
class database{

	//protected variables
  private:
    std::vector <zipcode>* zipvect;//holds all zipcode data
    std::vector <zipcode>* other;//holds zipcode data to benefit search function
      
 //public functions
  public:
	//constructor
    database();
	//destructor
    ~database();
	//outputs the current state of zipvect
	void output(std::string);
	//takes input from an input file  
    void input();
	//calls the correct search method
    void searchmethods();
	//asks for the user to choose a sorting method and calls quicksort
    void displaysort();
	//calls display with zipvect as the argument
    void partialdisplayzip();
	//display somefileds such as zipcode, city, sate, and county but not all fields
	//it also displays 30 of them
    void partialdisplay(std::vector <zipcode>);
	//display all fields of one zipcode
    void fulldisplay(std::string);
	//next three functions search based on a single field
    void searchbyzipcode(std::vector<zipcode>, std::string, int);
    void searchbycity(std::vector<zipcode>, std::string, int);
    void searchbystate(std::vector<zipcode>, std::string, int);
	//adds an instance of zipcode to the vector vipvect
    void addzipcode();
	//finds the distance between two zipcodes
    void finddistance(std::string, std::string);
	//swaps two zipcodes in vipvect based on their location
    void swap(int, int);
	//part of quicksort, zipvect into two smaller parts and makes sure a point 
	//called the pivot is larger than elements on the left and smaller then elements on the right
    int partition(std::string, int, int);
	//calls partition and calls quicksort recursively to sort zipvect
    void quicksort(std::string, int, int);
    
   
};

#endif
