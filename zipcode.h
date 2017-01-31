
#ifndef ZIPCODE_H_EXISTS
#define ZIPCODE_H_EXISTS

//class header
class zipcode{

	//private member variables in the order they are in the txt document
  private:
    std::string zip;
    std::string type;
    //no reason to have a decommisioned cat b/c none have been decommisioned
    std::string maincity; 
    std::string secondcity;
    //dont know what unacceptable city means so I didnt include it
    std::string state;
    std::string county;
    std::string timezone;
    std::string areacode;
    //didnt use country or world region b/c they are all America
    float latitude;
    float longitude;
    int population;

	//public functions
  public:
//default constructor only for user added data
    zipcode();
//copy constrctor
	void setequal(const zipcode&);
//overloaded construtor will be used more
    void input(std::string);
//destructor
    //~zipcode();
//other functions are all getters and setters
    std::string getzip();
    std::string gettype();
    std::string getmaincity();
    std::string getsecondcity();
    std::string getstate();
    std::string getcounty();
    std::string gettimezone();
    std::string getareacode();
    float getlatitude();
    float getlongitude();
    int getpopulation();
    void setzip(std::string);
    void settype(std::string);
    void setmaincity(std::string);
    void setsecondcity(std::string);
    void setstate(std::string);
    void setcounty(std::string);
    void settimezone(std::string);
    void setareacode(std::string);
    void setlatitude(std::string);
    void setlongitude(std::string);
    void setpopulation(std::string);

};//end zipcode header

#endif
