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

    //gets rid of decomissioned cause none of them had been decomissioned
    std::getline(ss, temp, '	');

    std::getline(ss, temp, '	');
    setmaincity(temp);

    std::getline(ss, temp, '	');
    setsecondcity(temp);

    //gets rid of unacceptable city
    std::getline(ss, temp, '	');
i
    std::getline(ss, temp, '	');
    setstate(temp);

    std::getline(ss, temp, '	');
    setcounty(temp);

    std::getline(ss, temp, '	');
    settimezone(temp);

    std::getline(ss, temp, '	');
    setareacode(temp);

    //this gets rid of country and world region
    std::getline(ss, temp, '	');
    std::getline(ss, temp, '	');

    std::getline(ss, temp, '	');
    setlatitude(temp);

    std::getline(ss, temp, '	');
    setlongitude(temp);

    std::getline(ss, temp, '	');
    setpopulation(temp);
 
  }
  
  std::string zipcode::getzip(){
  return *zip;
  }

  std::string zipcode::gettype(){
  return *type;
  }

  std::string zipcode::getmaincity(){
  return *maincity;
  }

  std::string zipcode::getsecondcity(){
  return *secondcity;
  }

  std::string zipcode::getstate(){
  return *state;
  }

  std::string zipcode::getcouty(){
  return *county;
  }

  std::string zipcode::gettimezone(){
  return *timezone;
  }

  std::string zipcode::getareacode(){
  return *areacode;
  }

  int zipcode::getlatitude(){
  return *latitiude;
  }

  int zipcode::getlongitude(){
  return *longitude;
  }

  int zipcode::getpopulation(){
  return *population;
  }

  void zipcode::setzip(std::string s){
  *zip = s;
  }

  void zipcode::settype(std::string s){
  *type = s;
  }

  void zipcode::setmaincity(std::string s){
  *maincity = s;
  }

  void zipcode::setsecondcity(std::string s){
  *secondcity = s;
  }

  void zipcode::setstate(std::string s){
  *state = s;
  }

  void zipcode::setcounty(std::string s){
  *county = s;
  }

  void zipcode::settimezone(std::string s){
  *timezone = s;
  }

  void zipcode::setareacode(std::string s){
  *areacode = s;
  }

  void zipcode::setlatitude(std::string s){
  *latitude = atoi(s.c_str());
  }

  void zipcode::setlongitude(std::string s){
  *longitude = atoi(s.c_str());
  }

  void zipcode::setpopulation(std::string s){
  *population = atoi(s.c_str());
  }


