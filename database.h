
#ifndef DATABASE_H_EXISTS
#define DATABASE_H_EXISTS

class database{

  protected:
    std::vector <zipcode> zipvect;
    std::vector <zipcode> temp;
      
 
  public:
    database();
    void partialdisplay(*zipcode);
    void fulldisplay(*zipcode);
    void searchbyzipcode(std::vector<zipcode>, std::string, int);
    void searchbycity(std::vector<zipcode>, std::string, int);
    void searchbystate(std::vector<zipcode>, std::string, int);
    void addzipcode();
    void finddistance(std::string, std::string);
    void sortbyzipcode();
    void sortbycity();
    void sortbystate();
   
};

#endif
