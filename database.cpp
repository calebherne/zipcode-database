#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "zipcode.h"
#include "database.h" 

  database::database(){

  zipvect = new std::vector <zipcode>; 
  other = new std::vector <zipcode>;  
  }
  
  database::~database(){
  delete zipvect;
  delete other;
  }
  
  void database::input(std::string z){

//REMEMBER FSTREAM FILE

  /*zipcode *a = new zipcode();
  a->setlatitude("73");
  a->setlongitude("43");
  a->setzip(z);
  zipvect->insert(zipvect->begin(), *a);
  delete a;*/
  }

  void database::searchmethods(){
    bool keepgoing = true;
    while(keepgoing){
      std::string search =" ";
      std::string choice =" ";
      std::cout<<"Sorting Methods\n\n";
      std::cout<<"(1) Search by Zipcode\n";
      std::cout<<"(2) Searcht by City\n";
      std::cout<<"(3) Search by State\n";
      std::cout<<"(4) Back\n\n";
      std::cin>>choice;
      std::cout<<"Enter Search\n";
      std::cin>>search;
      if(choice == "1"){searchbyzipcode(*zipvect, search, 0);}
      else if(choice == "2"){searchbycity(*zipvect, search, 0);}
      else if(choice == "3"){searchbystate(*zipvect, search, 0);}
      else if(choice == "4"){keepgoing = false;}
      else{std::cout<<"Your answer could not be understood, please enter one of the integers above.\n";}
    }
  }
  void database::displaysort(){
    std::string choice;
    std::cout<<"Sorting Methods\n\n";
    std::cout<<"(1) Sort by Zipcode\n";
    std::cout<<"(2) Sort by City\n";
    std::cout<<"(3) Sort by State\n";
    std::cin>>choice;
    quicksort(choice, 0, zipvect->size());
  }
  void database::partialdisplayzip(){
    partialdisplay(*zipvect);
  }  


  void database::partialdisplay(std::vector <zipcode> z){
   
  int i=0;
  std::string response;
  bool keepgoing = true;
  std::vector<zipcode>::iterator it = z.begin();
  while(keepgoing){
    std::cout<<"Zipcode     City                 County               State         \n";   
      while(it != zipvect->end() && i <30){
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
  void database::fulldisplay(std::string s){
  
  int notfound=0;
  bool keepgoing = true;
  std::vector<zipcode>::iterator it = zipvect->begin();
  while(keepgoing){

    if(it->getzip() == s){
    break;
    }

    if(it == zipvect->end()){
    notfound++;
    break;
    }
    it++; 
  }  
  
  if(notfound != 0){std::cout<<"Zipcode not found.\n";}
  else{ 
    std::cout<<it->getzip()<<"   "<<it->gettype()<<"   "<<it->getmaincity()<<"   ";
    std::cout<<it->getsecondcity()<<"   "<<it->getstate()<<"   "<<it->getcounty()<<"   ";
    std::cout<<it->gettimezone()<<"   "<<it->getlatitude()<<"   "<<it->getlongitude()<<"   ";
    std::cout<<it->getpopulation()<<"\n";
   }
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
      other->push_back(*it);
    }
    if(letter == 0){
      partialdisplay(*other);
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
      other->push_back(*it);
    }
    if(letter == 0){
      partialdisplay(*other);
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
      other->push_back(*it);
    }
    if(letter == 0){
      partialdisplay(*other);
    }
  }    

  void database::addzipcode(){
    std::string userzip = " ";
    std::cout<<"Please enter the zipcode and other information specified below seperated by tabs.\n";
    std::cout<<"zipcode, type, main city, secondary city, state, county, timezone, area code, latitude and longitude\n";
    std::cin>>userzip;
    
//FINISH

    zipcode* added = new zipcode(userzip);
    zipvect->insert(zipvect->begin(), *added);
    std::cout<<"zipcode has been added\n";
    delete added;
  }

  void database::finddistance(std::string s1, std::string s2){
    
    zipcode *place1 = new zipcode();
    zipcode *place2 = new zipcode();
    int i=0, j=0;
    std::vector<zipcode>::iterator it = zipvect->begin();
    while(it != zipvect->end()){
      while(i == 0){
        if(it->getzip() == s1 || it->getmaincity() == s1){
          *place1 = *it;
          i++;
        }
      }
      while(j == 0){
        if(it->getzip() == s2 || it->getmaincity() == s2){
          *place2 = *it;
          j++;
        }
      }
    }
   if(s1 != " " && s2 != " "){
    float distance;
    float x1, y1, x2, y2;     //converting to radians
    x1 = place1->getlongitude()*(3.14/180);
    y1 = place1->getlatitude()*(3.14/180);
    x2 = place2->getlongitude()*(3.14/180);
    y2 = place2->getlatitude()*(3.14/180); 
   
    //hevrsine equation
    distance = 2*6371*asin(sqrt(pow(sin((y2-y1)/2),2)+cos(y1)*cos(y2)*pow(sin((x2-x1)/2),2)));
    std::cout<<"The surface distance between theses two places is "<<distance<<"km.\n";
    std::cout<<"The distance in miles is "<<distance*.621371<<".\n";  
   }
   else{std::cout<<"You did not enter a valid zipcode.\n";}
   delete place1;
   delete place2;
  }

void database::swap(int a, int b){
  zipcode* temp = new zipcode();
  *temp = zipvect->at(a);
  zipvect->at(a) = zipvect->at(b);
  zipvect->at(b) = *temp;
  delete temp; 
}

void database::quicksort(std::string a, int lo, int hi){
  if(lo < hi){
    int p = partition(a,hi,lo);
    if(p == -1){
      return;
      }
    quicksort( a, lo, p);
    quicksort( a, p+1, hi);
  }
}

int database::partition(std::string a,int lo, int hi){
  std::string pivot;
  int i = lo;
  int j = hi;
  bool keepgoing = true;
  if(a== "1"){
  pivot = zipvect->at(lo).getzip();
  }
  else if(a == "2"){
  pivot = zipvect->at(lo).getmaincity();
  }
  else if(a == "3"){
  pivot = zipvect->at(lo).getstate();
  }
  else{
    std::cout<<"you did not choose sorting method, 1, 2, or 3.\n";
    return (-1);
  }
  while(keepgoing){
    if(a == "1"){
      while(zipvect->at(i).getzip()< pivot){i = i+1;}
      while(zipvect->at(j).getzip()> pivot){j = j-1;}
      if(i >= j){return j;}
      swap(i,j);
    }
    if(a == "2"){
      while(zipvect->at(i).getmaincity()< pivot){i = i+1;}
      while(zipvect->at(j).getmaincity()> pivot){j = j-1;}
      if(i >= j){return j;}
      swap(i,j);
    }
    if(a == "3"){
      while(zipvect->at(i).getstate()< pivot){i = i+1;}
      while(zipvect->at(j).getstate()> pivot){j = j-1;}
      if(i >= j){return j;}
      swap(i,j);
    }
  }
}

















