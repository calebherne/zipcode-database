
#ifndef ZIPCODE_H_EXISTS
#define ZIPCODE_H_EXISTS

class zipcode{

  protected:
    int zip;
    std::string type;
    //no reason to have a decommisioned cat b/c none 
    //have been decommisioned
    std::string maincity; 
    std::string secondcity;
    //dont know what unacceptable city means so I didnt include it
    std::string state;
    std::string county;
    std::string timezone;
    std::string areacode;
    //didnt use country or world region b/c they are all America
    std::string latitiude;
    std::string longitude;
    int population;
