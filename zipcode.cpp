#include <iostream>
#include <sstream>
#include "zipcode.h"


  zipcode::zipcode::zipcode(){
    *zip = "n/a";
    *type = "n/a";
    *maincity = "n/a";
    *secondcity = "n/a";
    *state = "n/a";
    *county = "n/a";
    *timezone = "n/a";
    *areacode = "n/a";
    *latitude = 0;
    *longitude = 0;
    *population = 0;
  }
  zipcode::zipcode(std::string s){
    std::stringstream ss;
    ss<<s;
    std::string temp;

    std::getline(ss, temp, '	');
    setzip(temp);

    std::getline(ss, temp, '	');
    settype(temp);

    std::getline(ss, temp, '	');
    setmaincity(temp);

    std::getline(ss, temp, '	');
    setsecondcity(temp);

    std::getline(ss, temp, '	');
    setstate(temp);

    std::getline(ss, temp, '	');
    setcounty(temp);

    std::getline(ss, temp, '	');
    settimezone(temp);

    std::getline(ss, temp, '	');
    setareacode(temp);

    std::getline(ss, temp, '	');
    setlatitude(temp);

    std::getline(ss, temp, '	');
    setlongitude(temp);

    std::getline(ss, temp, '	');
    setpopulation(temp);
 
  }
  
  std::string zipcode::getzip();
  std::string zipcode::gettype();
  std::string zipcode::getmaincity();
  std::string zipcode::getsecondcity();
  std::string zipcode::getstate();
  std::string zipcode::getcouty();
  std::string zipcode::gettimezone();
  std::string zipcode::getareacode();
  int zipcode::getlatitude();
  int zipcode::getlongitude();
  int zipcode::getpopulation();
  void zipcode::setzip(std::string);
  void zipcode::settype(std::string);
  void zipcode::setmaincity(std::string);
  void zipcode::setsecondcity(std::string);
  void zipcode::setstate(std::string);
  void zipcode::setcounty(std::string);
  void zipcode::settimezone(std::string);
  void zipcode::setareacode(std::string);
  void zipcode::setlatitude(std::string);
  void zipcode::setlongitude(std::string);
  void zipcode::setpopulation(std::string);

