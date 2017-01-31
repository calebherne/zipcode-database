#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "zipcode.h"


//default constuctor
  zipcode::zipcode(){
    //declares on the heap and gives default values
    /*zip = new std::string();
    type = new std::string();
    maincity = new std::string();
    secondcity = new std::string();
    state = new std::string();
    county = new std::string();
    timezone = new std::string();
    areacode = new std::string();
    latitude = new float;
    longitude = new float;
    population = new int;*/
    zip = "n/a";
    type = "n/a";
    maincity = "n/a";
    secondcity = "n/a";
    state = "n/a";
    county = "n/a";
    timezone = "n/a";
    areacode = "n/a";
    latitude = 0;
    longitude = 0;
    population = 0;
  }
  //resembles a copy constructor but i am not declaring variables on the heap, this is just so i can set 
  //existing zipcode instances equal to eachother
  void zipcode::setequal(const zipcode &z)
  {
	 
	  zip = z.zip;
	  type = z.type;
	  maincity = z.maincity;
	  secondcity = z.secondcity;
	  state = z.state;
	  county = z.county;
	  timezone = z.timezone;
	  areacode = z.areacode;
	  latitude = z.latitude;
	  longitude = z.longitude;
	  population = z.population;
  }
  //overloaded constructor
  void zipcode::input(std::string s){
        
	//declares on the heap but also parses a string and calls setters
	//this data is tab delimited thus getline uses tabs
   /* zip = new std::string();
    type = new std::string();
    maincity = new std::string();
    secondcity = new std::string();
    state = new std::string();
    county = new std::string();
    timezone = new std::string();
    areacode = new std::string();
    latitude = new float;
    longitude = new float;
    population = new int;*/
    
	//opens a string stream to take in the long string 
    std::stringstream ss;
    std::string temp;  
    ss<<s; 
    
	//getiline is used to break this string into individual fields
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

    //gets rid of unacceptable 
    std::getline(ss, temp, '	');
       

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

	//a newline character is added to the end thus this is a regular getline
    std::getline(ss, temp);
    setpopulation(temp);
    }

  //destructor
  /*zipcode::~zipcode(){
	  
  
  delete zip;
  delete type;
  delete maincity;
  delete secondcity;
  delete state;
  delete county;
  delete timezone;
  delete areacode;
  delete latitude;
  delete longitude;
  delete population;
  }  */

  //get functions get private data
  std::string zipcode::getzip(){
  return zip;
  }

  std::string zipcode::gettype(){
  return type;
  }

  std::string zipcode::getmaincity(){
  return maincity;
  }

  std::string zipcode::getsecondcity(){
  return secondcity;
  }

  std::string zipcode::getstate(){
  return state;
  }

  std::string zipcode::getcounty(){
  return county;
  }

  std::string zipcode::gettimezone(){
  return timezone;
  }

  std::string zipcode::getareacode(){
  return areacode;
  }

  float zipcode::getlatitude(){
  return latitude;
  }

  float zipcode::getlongitude(){
  return longitude;
  }

  int zipcode::getpopulation(){
  return population;
  }

  //setter put entered data into private variables
  void zipcode::setzip(std::string s){
  zip = s;
  }

  void zipcode::settype(std::string s){
  type = s;
  }

  void zipcode::setmaincity(std::string s){
  maincity = s;
  }

  void zipcode::setsecondcity(std::string s){
  secondcity = s;
  }

  void zipcode::setstate(std::string s){
  state = s;
  }

  void zipcode::setcounty(std::string s){
  county = s;
  }

  void zipcode::settimezone(std::string s){
  timezone = s;
  }

  void zipcode::setareacode(std::string s){
  areacode = s;
  }

  //use atof and atoi to convert strings to ints to be stored
  //this allows a later function to use their float values to calculate distance
  void zipcode::setlatitude(std::string s){
  latitude = atof(s.c_str());
  }

  void zipcode::setlongitude(std::string s){
  longitude = atof(s.c_str());
  }

  void zipcode::setpopulation(std::string s){
  population = atoi(s.c_str());
  }
  

  
