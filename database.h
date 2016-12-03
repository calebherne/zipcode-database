
#include "zipcode.h"
#include <vector>
#ifndef DATABASE_H_EXISTS
#define DATABASE_H_EXISTS

class database{

  protected:
    std::vector <zipcode>* zipvect;
    std::vector <zipcode>* other;
      
 
  public:
    database();
    ~database();
    void input(std::string);
    void searchmethods();
    void displaysort();
    void partialdisplayzip();
    void partialdisplay(std::vector <zipcode>);//consider passing an iterator or a vector
    void fulldisplay(std::string);
    void searchbyzipcode(std::vector<zipcode>, std::string, int);
    void searchbycity(std::vector<zipcode>, std::string, int);
    void searchbystate(std::vector<zipcode>, std::string, int);
    void addzipcode();
    void finddistance(std::string, std::string);
    void swap(int, int);
    int partition(std::string, int, int);
    void quicksort(std::string, int, int);
    //void sortbycity(int, int);
    //void sortbystate();
   
};

#endif
