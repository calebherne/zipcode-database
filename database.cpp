#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "zipcode.h"
#include "database.h" 

  database::database(){
  zipcode a = zipcode();
  zipcode b = zipcode();
  a.setlatitude("73");
  a.setlongitude("43");
  b.setlatitude("73");
  b.setlongitude("43");
  a.setzip("1");
  b.setzip("2");
  zipvect.push_back(a);
  zipvect.push_back(b); 
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
        for(int j = it->getmaincity().length(); j<20; j++){
          std::cout<<" ";
        }
        std::cout<<it->getcounty();
        for(int j = it->getcounty().length(); j<20; j++){
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
    else{std::cout<<"I'm sorry, that is not a valid response.\n";}
  }
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
      temp = it->getzip();
      if(temp [letter] == search [letter]){
        yes.push_back(*it);
      }
      else{no.push_back(*it);}
    }
    if(!yes.empty()){
      letter++;
      searchbyzipcode(yes, search, letter);
    }
    it = yes.begin();
    while(it != yes.end()){
      other.push_back(*it);
    }
  }    
      
      
  void database::searchbycity(std::vector<zipcode> works, std::string search, int letter){
    
    std::string temp;
    std::vector<zipcode> yes, no;
    std::vector<zipcode>::iterator it = works.begin();
    while(it != works.end()){
      temp = it->getmaincity();
      if(temp [letter] == search [letter]){
        yes.push_back(*it);
      }
      else{no.push_back(*it);}
    }
    if(!yes.empty()){
      letter++;
      searchbycity(yes, search, letter);
    }
    it = yes.begin();
    while(it != yes.end()){
      other.push_back(*it);
    }
  }    
  
  
  void database::searchbystate(std::vector<zipcode> works, std::string search, int letter){
    
    std::string temp;
    std::vector<zipcode> yes, no;
    std::vector<zipcode>::iterator it = works.begin();
    while(it != works.end()){
      temp = it->getstate();
      if(temp [letter] == search [letter]){
        yes.push_back(*it);
      }
      else{no.push_back(*it);}
    }
    if(!yes.empty()){
      letter++;
      searchbystate(yes, search, letter);
    }
    it = yes.begin();
    while(it != yes.end()){
      other.push_back(*it);
    }
  }    

  void database::addzipcode(){
    std::string userzip;
    std::cout<<"Please enter the zipcode and other information specified below seperated by tabs.\n";
    std::cout<<"zipcode, type, main city, secondary city, state, county, timezone, area code, latitude and longitude\n";
    std::cin>>userzip;
    
//FINISH

    zipcode added = zipcode(userzip);
    zipvect.insert(zipvect.begin(), added);
    std::cout<<"zipcode has been added\n";
  }

  void database::finddistance(std::string s1, std::string s2){
    zipcode place1, place2;
    int i=0, j=0;
    std::vector<zipcode>::iterator it = zipvect.begin();
    while(it != zipvect.end()){
      while(i == 0){
        if(it->getzip() == s1 || it->getmaincity() == s1){
          place1 = *it;
          i++;
        }
      }
      while(j == 0){
        if(it->getzip() == s2 || it->getmaincity() == s2){
          place2 = *it;
          j++;
        }
      }
    }
   float distance;
   float x1, y1, x2, y2;     //converting to radians
   x1 = place1.getlongitude()*(3.14/180);
   y1 = place1.getlatitude()*(3.14/180);
   x2 = place2.getlongitude()*(3.14/180);
   y2 = place2.getlatitude()*(3.14/180); 
   
   //hevrsine equation
   distance = 2*6371*asin(sqrt(pow(sin((y2-y1)/2),2)+cos(y1)*cos(y2)*pow(sin((x2-x1)/2),2)));
   std::cout<<"The surface distance between theses two places is "<<distance<<"km.\n";
   std::cout<<"The distance in miles is "<<distance*.621371<<".\n";  
  }

void swap(int a, int b){
  zipcode* temp = new zipcode();
  *temp = zipvect[a];
  zipvect[a] = zipvect[b];
  zipvect[b] = *temp;
  delete temp; 
}

void quicksort(int a, int lo, int hi){
  if(lo < hi){
    int p = partition(a,hi,lo);
    if(p == -1){
      return;
      }
    quicksort( a, lo, p);
    quicksort( a, p+1, hi);
  }
}

int partition(int a,int lo, int hi){
  std::string pivot;
  int i = lo;
  int j = hi;
  bool keepgoing = true;
  if(a== 1){
  pivot = zipvect[lo].getzip();
  }
  else if(a == 2){
  pivot = zipvect[lo].getmaincity();
  }
  else if(a == 3){
  pivlot = zipvect[lo].getstate();
  }
  else{
    std::cout<<"you did not choose sorting method, 1, 2, or 3.\n";
    return (-1);
  }
  while(keepgoing){
    if(a == 1){
      while(zipvect[i].getzip()< pivot){i = i+1;}
      while(zipvect[j].getzip()> pivot){j = j-1;}
      if(i >= j){return j;}
      swap(i,j);
    }
    if(a == 2){
      while(zipvect[i].getmaincity()< pivot){i = i+1;}
      while(zipvect[j].getmaincity()> pivot){j = j-1;}
      if(i >= j){return j;}
      swap(i,j);
    }
    if(a == 3){
      while(zipvect[i].getstate()< pivot){i = i+1;}
      while(zipvect[j].getstate()> pivot){j = j-1;}
      if(i >= j){return j;}
      swap(i,j);
    }
  }
}    






















