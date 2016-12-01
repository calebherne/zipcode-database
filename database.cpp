#include <iostream>
#include <string>
#include "zipcode.h"
#include "database.h" 

  database::database(){
    
  }
  void database::partialdisplay(zipcode z){
   
  int i=0;
  std::string response;
  bool keepgoing = true;
  std::vector<zipcode>::iterator it = zipvect.begin();
  while(keepgoing){
    std::cout<<"Zipcode     City                 County               State         \n";   
      while(it != zipvect.end() && i <30){
        std::cout<<it->getzip();
        std::cout<<"      ";
        std::cout<<it->getmaincity();
        for(int j = it->getmaincity().lenght(); j<20; j++){
          std::cout<<" ";
        }
        std::cout<<it->getcounty();
        for(int j = it->getcounty().lenght(); j<20; j++){
          std::cout<<" ";
        }
        std::cout<<it->getstate();
        std::cout<<"       \n ";
      }
    response = " ";
    while(response != "1" && response !="2")
    std::cout<<"Press 1 for more results, Press 2 to go back to the main menu\n";
    std::cin>>response;
    
    if(response == "1"){}
    else if(response == "2"){keepgoing = false;}
    else{std::cout<<"I'm sorry, that is not a valid response.\n"}
  }
  
  void database::fulldisplay(zipcode z){
  
  std::cout<<z.getzip()<<"   "<<z.gettype()<<"   "<<z.getmaincity()<<"   ";
  std::cout<<z.getsecondcity()<<"   "<<z.getstate()<<"   "<<z.getcounty()<<"   ";
  std::cout<<z.gettimezone()<<"   "<<z.getlatitude()<<"   "<<z.getlongitude()<<"   ";
  std::cout<<z.getpopulation()<<"\n";
  
  }
  
  //make sure to pass 0 as letter
  void database::searchbyzipcode(std::vector<zipcode> works, std::string search, int letter){
    
  //could make this a loop instead of recursion if neccessary using v.insert()
    std::string temp;
    std::vector<zipcode> yes, no;
    std::vector<zipcode>::iterator it = works.begin();
    while(it != works.end()){
      temp = *it.getzip();
      if(temp [letter] == search [letter]){
        yes.push_back(*it);
      }
      else{no.push_back(*it)}
    }
    if(yes != NULL){
      letter++;
      searchbyzipcode(yes, search, letter)
    }
    it = yes.begin();
    while(it != yes.end()){
      temp.push_back(*it);
    }
  }    
      
      
  void database::searchbycity(std::vector<zipcode> works, std::string search, int letter){
    
    std::string temp;
    std::vector<zipcode> yes, no;
    std::vector<zipcode>::iterator it = works.begin();
    while(it != works.end()){
      temp = *it.getmaincity();
      if(temp [letter] == search [letter]){
        yes.push_back(*it);
      }
      else{no.push_back(*it)}
    }
    if(yes != NULL){
      letter++;
      searchbycity(yes, search, letter)
    }
    it = yes.begin();
    while(it != yes.end()){
      temp.push_back(*it);
    }
  }    
  
  
  void database::searchbystate(std::vector<zipcode> works, std::string search, int letter){
    
    std::string temp;
    std::vector<zipcode> yes, no;
    std::vector<zipcode>::iterator it = works.begin();
    while(it != works.end()){
      temp = *it.getstate();
      if(temp [letter] == search [letter]){
        yes.push_back(*it);
      }
      else{no.push_back(*it)}
    }
    if(yes != NULL){
      letter++;
      searchbystate(yes, search, letter)
    }
    it = yes.begin();
    while(it != yes.end()){
      temp.push_back(*it);
    }
  }    

  void database::addzipcode(std::string input){
    zipcode added = zipcode(input);
    zipvect.insert(zipvect.begin, added);
    std::cout<<"zipcode has been added\n;
  }

  void database::finddistance(std::string s1, std::string s2){
    zipcode place1, place2;
    int i=0, j=0;
    std::vector<zipcode>::iterator it = zipvect.begin();
    while(it != zipvect.end()){
      while(i == 0){
        if(*it.getzip() == s1 || *it.getmaincity() == s1){
          place1 = *it;
          i++;
        }
      }
      while(j == 0){
        if(*it.getzip() == s2 || *it.getmaincity() == s2){
          place2 = *it;
          j++;
        }
      }
    }
   
  }





      






















