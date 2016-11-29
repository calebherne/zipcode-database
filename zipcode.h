
#ifndef ZIPCODE_H_EXISTS
#define ZIPCODE_H_EXISTS

class zipcode{

  protected:
    int* zip;
    std::string* type;
    //no reason to have a decommisioned cat b/c none 
    //have been decommisioned
    std::string* maincity; 
    std::string* secondcity;
    //dont know what unacceptable city means so I didnt include it
    std::string* state;
    std::string* county;
    std::string* timezone;
    std::string* areacode;
    //didnt use country or world region b/c they are all America
    int* latitiude;
    int* longitude;
    int* population;

  public:

    zipcode();
    zipcode(std::string);
    ~zipcode();
    int getzip();
    std::string gettype();
    std::string getmaincity();
    std::string getsecondcity();
    std::string getstate();
    std::string getcouty();
    std::string gettimezone();
    std::string getareacode();
    int getlatitude();
    int getlongitude();
    int getpopulation();
    void setzip(int);
    void settype(std::string);
    void setmaincity(std::string);
    void setsecondcity(std::string);
    void setstate(std::string);
    void setcounty(std::string);
    void settimezone(std::string);
    void setareacode(std::string);
    void setlatitude(int);
    void setlongitude(int);
    void setpopulation(int);

};

#endif
