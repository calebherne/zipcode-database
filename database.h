
#include "zipcode.h"
#include <vector>
#ifndef DATABASE_H_EXISTS
#define DATABASE_H_EXISTS

class database{

  protected:
    std::vector <zipcode> zipvect;
    std::vector <zipcode> other;
      
 
  public:
    database();
    void partialdisplay(zipcode);//consider passing an iterator or a vector
    void fulldisplay(zipcode);
    void searchbyzipcode(std::vector<zipcode>, std::string, int);
    void searchbycity(std::vector<zipcode>, std::string, int);
    void searchbystate(std::vector<zipcode>, std::string, int);
    void addzipcode();
    void finddistance(std::string, std::string);
    void swap(int, int);
    void partition(int, int);
    void quicksort(int,int, int);
    //void sortbycity(int, int);
    //void sortbystate();
   
};

#endif
