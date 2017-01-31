#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "zipcode.h"
#include "database.h" 




  //parse the input file containing all zipcodes in the US
  void database::input() {
	  
	  zipcode zip = zipcode();
	  std::string temp;
	  //opens file to read in input
	  std::ifstream inputs;
	  //loops until the entire text document has been read
//	  inputs.open("zip_code_database.txt");
          inputs.open("zip_code_database.txt");
	  //firts gelitne gets rid of header
	  std::getline(inputs, temp);
	  while (std::getline(inputs, temp)) {
		  //braks file into pieces that the zipcode constructor can use
		  zip.input(temp + "\n");
		  zipvect.push_back(zip);
	  }
	  inputs.close();
  }

  //creates an output file of the current state of the database, a '.'has been added in place of 
  //the fields that dont matter so that this file could be used as input for this program if the
  //the user names the file the same thing as the input file
  void database::output(std::string s) {

	  //input from user plus and then added .txt to make sure 
	  //it is saved as a text file
	  std::string file = s + ".txt";
	  std::ofstream output;
	  output.open(file.c_str());
	  //periods are used where inconsequantial data is placed so that it will be parced correctly
	  std::vector<zipcode>::iterator it = zipvect.begin();
	  output << "zip	type	.	main_city	secondary_city	.	state	county	timezone	areacode	.	.	latitude	longitude	population\n";
	  while (it != zipvect.end()) {
		  output<<it->getzip()<<"	"<<it->gettype()<<"	.	"<<it->getmaincity()<<"	";
		  output<<it->getsecondcity()<<"	.	"<<it->getstate()<<"	"<<it-> getcounty();
		  output<<"	"<<it->gettimezone()<<"	"<<it->getareacode()<<"	.	.	"<<it->getlatitude();
		  output <<"	" << it->getlongitude() << "	" << it->getpopulation() << "\n";
                  it++;
	  }
	  output.close();
  }
  //user inputs how to search and the program calls the corresponding function
  void database::searchmethods(){
	  //loops until condition is met
    bool keepgoing = true;
    while(keepgoing){
      std::string search =" ";
      std::string choice =" ";
	  //outputs menu for user
      std::cout<<"Search Methods\n\n";
      std::cout<<"(1) Search by Zipcode\n";
      std::cout<<"(2) Search by City\n";
      std::cout<<"(3) Search by State\n";
      std::cout<<"(4) Back\n\n";
	  //user enters choice and search
      //std::cin>>choice;
      std::getline(std::cin, choice); 
           
	  //checks what was chosen and calls the corresponding function
      if(choice == "1"){
        std::cout<<"Enter Search\n";
        std::getline(std::cin, search);
        searchbyzipcode(zipvect, search, 0);}
      else if(choice == "2"){
        std::cout<<"Enter Search\n";
        std::cout<<"Remember to capitalize the first letter of the city.\n"; 
        std::getline(std::cin, search);
	searchbycity(zipvect, search, 0);}
      else if(choice == "3"){
        std::cout<<"Enter Search\n";
        std::cout<<"Remember to capitalize the state search.\n"; 
        std::getline(std::cin, search);
	searchbystate(zipvect, search, 0);}
      else if(choice == "4"){keepgoing = false;}
      else{std::cout<<"Your answer could not be understood, please enter one of the integers above.\n";}
    }
  }

  //asks the user how they would like to sort the database and acts accordingly
  void database::displaysort(){
    std::string choice;
	//menu
    std::cout<<"Sorting Methods\n\n";
    std::cout<<"(1) Sort by Zipcode\n";
    std::cout<<"(2) Sort by City\n";
    std::cout<<"(3) Sort by State\n";
    std::getline(std::cin,choice);
	//custom quicksort function has the capability to sort by each method built in
    quicksort(choice, 0, (int)(zipvect.size()-1));
  }

  //calls partial display on the zipvect
  //this is a function because it was the best way to have zipvect as an argument
  //while still allowing other vectors to be sorted
  void database::partialdisplayzip(){
    partialdisplay(zipvect);
  }  

  //displays 4 zipcode fields and 30 zipcodes, most useful for searching
  void database::partialdisplay(std::vector <zipcode>& z) {

	  int i = 0;
	  std::string response;
	  bool keepgoing = true;
	  //iterator pointing to the beginning of the vector passed in
	  std::vector<zipcode>::iterator it = z.begin();
	  //keeps looping until 30 have been outputed
	  while (keepgoing) {
                  i = 0;
		  std::cout << "Zipcode     City                 County               State         \n";
		  while (it != z.end() && i < 30) {
			  std::cout << it->getzip();
                          for(int j = it->getzip().length(); j<10; j++){
			  	 std::cout<<" ";
			  }
			  std::cout << it->getmaincity();
			  //these keep spacing consitent
			  for (int j = it->getmaincity().length(); j < 20; j++) {
				  std::cout << " ";
			  }
			  std::cout << it->getcounty();
			  for (int j = it->getcounty().length(); j < 25; j++) {
				  std::cout << " ";
			  }
                          std::cout << it->getstate();
			  std::cout << " \n";
                          i++;
                          it++;
		  }
		  response = " ";
		  //if the vector ended the user will not be asked if they would like to see more
		  if (it == z.end()) { response = 2; }
		  //checks whether the user wants to display 30 more results or stop
		  while (response != "1" && response != "2") {
			  std::cout << "Press 1 for more results, Press 2 to go back to the main menu\n";
			  std::cin >> response;

			  if (response == "1") {}
			  else if (response == "2") { keepgoing = false; }
			  else { std::cout << "I'm sorry, that is not a valid response.\n"; }
		  }
	  }
  }

  //displays all the fields of one element that the user specifies
  void database::fulldisplay(std::string s){
  
  int notfound=0;
  bool keepgoing = true;
  //sets iterator to the begining of zipvect
  std::vector<zipcode>::iterator it = zipvect.begin();
  while(keepgoing){
	  //stops if the element is found or if the end of zipvect is rechec

    if(it->getzip() == s){
    break;
    }

    if(it == zipvect.end()){
    notfound++;
    break;
    }
    it++; 
  }  
  
  if(notfound != 0){std::cout<<"Zipcode not found.\n";}
  //outputs all fields of a zipcode
  else{ 
    std::cout<<it->getzip()<<"   "<<it->gettype()<<"   "<<it->getmaincity()<<"   ";
    std::cout<<it->getsecondcity()<<"   "<<it->getstate()<<"   "<<it->getcounty()<<"   ";
    std::cout<<it->gettimezone()<<"   "<<it->getlatitude()<<"   "<<it->getlongitude()<<"   ";
    std::cout<<it->getpopulation()<<"\n\n";
   }
 }
  
  //searches for a specified and partially displays all potential results
  void database::searchbyzipcode(std::vector<zipcode>& works, std::string search, int letter){
    
    std::string temp = " ";
    std::vector<zipcode> yes;
    std::vector<zipcode>::iterator it2;
    std::vector<zipcode>::iterator it = works.begin();
  
	//itterates through the whole vector that was passed
    if(letter == search.size()){
	it = works.end();
    }
    while(it != works.end()){
      temp = it->getzip();
         
	  //chekcs if the search string and zipcode have the same character in the positions
	  //specified by the letter int
      if(temp.size() > letter){
	  
        if(temp[letter] == search[letter]){
             
	  	  //if they are equal they are plut in a vector of other zipcodes that have similar char's
          yes.push_back(*it);
        }
      }
     it++; 
    }
  	//if any zipcodes share a letter in the specified location, than the function
    	//is called recursively to check the next letter
    	
    if(!yes.empty()&& letter != search.size()){
      letter++;
      searchbyzipcode(yes, search, letter);
      letter--;
    }
	//once the recursion is over all the zipcodes that were in the yes vector will be added to other
	//vector in the order of most similar letters to least not including the same zipcode twice
    
    it = yes.begin();
    int x;
     
    while(it != yes.end()){
		x=0;
		it2 = other.begin();
		while (it2 != other.end()) {
			if (it->getzip() == it2->getzip()) { x++;}
                       it2++;
		}
		if (x == 0) {
                        other.push_back(*it);
		}
         it++;
    }
	//calls partial display once since letter will only equal zero the first time
    if(letter == 0){
     
      partialdisplay(other);
      other.clear();
    }
	//clears other vector so that it will be ready fo the next search
	
  }    
      
  void database::searchbycity(std::vector<zipcode>& works, std::string search, int letter){
    
    std::string temp = " ";
    std::vector<zipcode> yes;
    std::vector<zipcode>::iterator it2;
    std::vector<zipcode>::iterator it = works.begin();
  
	//itterates through the whole vector that was passed
    if(letter == search.size()){
	it = works.end();
    }
    while(it != works.end()){
      temp = it->getmaincity();
         
	  //chekcs if the search string and zipcode have the same character in the positions
	  //specified by the letter int
      if(temp.size() > letter){
	  
        if(temp[letter] == search[letter]){
             
	  	  //if they are equal they are plut in a vector of other zipcodes that have similar char's
          yes.push_back(*it);
        }
      }
     it++; 
    }
  	//if any zipcodes share a letter in the specified location, than the function
    	//is called recursively to check the next letter
    	
    if(!yes.empty()&& letter != search.size()){
      letter++;
      searchbycity(yes, search, letter);
      letter--;
    }
	//once the recursion is over all the zipcodes that were in the yes vector will be added to other
	//vector in the order of most similar letters to least not including the same zipcode twice
    
    it = yes.begin();
    int x;
     
    while(it != yes.end()){
		x=0;
		it2 = other.begin();
		while (it2 != other.end()) {
			if (it->getzip() == it2->getzip()) { x++;}
                       it2++;
		}
		if (x == 0) {
                        other.push_back(*it);
		}
         it++;
    }
	//calls partial display once since letter will only equal zero the first time
    if(letter == 0){
     
      partialdisplay(other);
      other.clear();
    }
	//clears other vector so that it will be ready fo the next search
	
  }    
  void database::searchbystate(std::vector<zipcode>& works, std::string search, int letter){
    
    std::string temp = " ";
    std::vector<zipcode> yes;
    std::vector<zipcode>::iterator it2;
    std::vector<zipcode>::iterator it = works.begin();
  
	//itterates through the whole vector that was passed
    if(letter == search.size()){
	it = works.end();
    }
    while(it != works.end()){
      temp = it->getstate();
         
	  //chekcs if the search string and zipcode have the same character in the positions
	  //specified by the letter int
      if(temp.size() > letter){
	  
        if(temp[letter] == search[letter]){
             
	  	  //if they are equal they are plut in a vector of other zipcodes that have similar char's
          yes.push_back(*it);
        }
      }
     it++; 
    }
  	//if any zipcodes share a letter in the specified location, than the function
    	//is called recursively to check the next letter
    	
    if(!yes.empty()&& letter != search.size()){
      letter++;
      searchbystate(yes, search, letter);
      letter--;
    }
	//once the recursion is over all the zipcodes that were in the yes vector will be added to other
	//vector in the order of most similar letters to least not including the same zipcode twice
    
    it = yes.begin();
    int x;
     
    while(it != yes.end()){
		x=0;
		it2 = other.begin();
		while (it2 != other.end()) {
                        //still use get zip since zipcodes are unique foe each location
			if (it->getzip() == it2->getzip()) { x++;}
                       it2++;
		}
		if (x == 0) {
                        other.push_back(*it);
		}
         it++;
    }
	//calls partial display once since letter will only equal zero the first time
    if(letter == 0){
     
      partialdisplay(other);
      other.clear();
    }
	//clears other vector so that it will be ready fo the next search
  }    
   
  //adds a zipcode to tvipvect
  void database::addzipcode(){
	  zipcode z = zipcode();
    std::string userzip = " ";
    std::cout<<"Please enter the zipcode and other information listed, if you dont know something type n/a.\n";
	//creates a new instance of zipcode in zipvect
	zipvect.insert(zipvect.begin(), z);
	//all this is to make input harder for the user to mess up
	//initially was going to have them seperate by tabs but they would mess it up
	std::cout << "Zipcode:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setzip(userzip);
	std::cout << "\ntype:";
	std::getline(std::cin,userzip);
	zipvect.at(0).settype(userzip);
	std::cout << "\nmaincity:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setmaincity(userzip);
	std::cout << "\nsecondarycity:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setsecondcity(userzip);
	std::cout << "\nstate:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setstate(userzip);
	std::cout << "\ncounty:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setcounty(userzip);
	std::cout << "\ntimezone:";
	std::getline(std::cin,userzip);
	zipvect.at(0).settimezone(userzip);
	std::cout << "\nareacode:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setareacode(userzip);
	std::cout << "\nlatitude:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setlatitude(userzip);
	std::cout << "\nlongitude:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setlongitude(userzip);
	std::cout << "\npopulation:";
	std::getline(std::cin,userzip);
	zipvect.at(0).setpopulation(userzip);
	std::cout << "\n";
  }

  //finds the distance between two zipcodes
  void database::finddistance(std::string s1, std::string s2){
    
     
    zipcode place1 = zipcode();
    zipcode place2 = zipcode();
    int i=0, j=0;
	//finds the two zipcodes you entered
    std::vector<zipcode>::iterator it = zipvect.begin();
    while(it != zipvect.end()){
      if(i == 1 && j == 1){break;}
      if(i==0){
        if(it->getzip() == s1 || it->getmaincity() == s1){
          place1.setequal(*it);
          i++;
        }
      }
      if(j==0){ 
        if(it->getzip() == s2 || it->getmaincity() == s2){
          place2.setequal(*it);
          j++;
        }  
      }
      it++;
    }
	//if your two zipcodes exist then the program continues
   if(i != 0 && j != 0){
    float distance;
    float x1, y1, x2, y2;     //converting to radians
    x1 = place1.getlongitude()*(M_PI/180);
    y1 = place1.getlatitude()*(M_PI/180);
    x2 = place2.getlongitude()*(M_PI/180);
    y2 = place2.getlatitude()*(M_PI/180); 
   
    //hevrsine equation finds surface distance
    distance = 2*6371*asin(sqrt(pow(sin((y2-y1)/2),2)+cos(y1)*cos(y2)*pow(sin((x2-x1)/2),2)));
    std::cout<<"The surface distance between theses two places is "<<distance<<"km.\n";
    std::cout<<"The distance in miles is "<<distance*.621371<<".\n";  
   }
   //else happens if the program cannot find the zipcode
   else{std::cout<<"You did not enter a valid zipcode.\n";}
   
  }

  //swaps two zipcodes in zipvect
void database::swap(int a, int b){
  //a and b are locations in the vector
  
  zipcode temp = zipcode();
  //uses set equal like an equal sign would on regular variables
  temp.setequal(zipvect.at(a));
  zipvect.at(a).setequal(zipvect.at(b));
  zipvect.at(b).setequal(temp);

   
}

//sorts elements of zipvect
void database::quicksort(std::string a, int lo, int hi){
  //lo and hi are essentially indices in zipvect
   
  if(lo < hi){
  
	//p is the pivot point that the program uses 
	//all values less than pivot are put on the left, and all values greater 
	//are to the right of it
    int p = partition(a,lo,hi);
	//I added p == -1 to test for bad user input;
    if(p == -1){
      return;
      }
	//breaks vector into two parts and calls quicksort on each
    quicksort( a, lo, p);
    quicksort( a, p+1, hi);
  }
}

//finds a pivot points to break vector into smaller parts
int database::partition(std::string a,int lo, int hi){
  //pivot is described above
  
  std::string pivot;
  int i = lo;
  int j = hi;
  bool keepgoing = true;
  //checks which sorting method the user would like to use
  if(a== "1"){
  pivot = zipvect.at(lo).getzip();
  }
  else if(a == "2"){
  pivot = zipvect.at(lo).getmaincity();
  }
  else if(a == "3"){
  pivot = zipvect.at(lo).getstate();
  }
  //if the user did not enter input correctly they are notified
  else{
    std::cout<<"you did not choose sorting method, 1, 2, or 3.\n";
    return (-1);
  }
  //loops until i>=j meaning until the indices are pointing to the same place or have overlapped
  i--;
  j++;
  while(keepgoing){
    if(a == "1"){
      do{i = i+1;
      }
      while(zipvect.at(i).getzip()< pivot);
      do{j = j-1;}
      while(zipvect.at(j).getzip()> pivot);
      if(i >= j){return j;}
      swap(i,j);
    }
    if(a == "2"){
      do{i = i+1;}
      while(zipvect.at(i).getmaincity()< pivot);
      do{j = j-1;}
      while(zipvect.at(j).getmaincity()> pivot);
      if(i >= j){return j;}
      swap(i,j);
    }
    if(a == "3"){
      do{i = i+1;}
      while(zipvect.at(i).getstate()< pivot);
      do{j = j-1;}
      while(zipvect.at(j).getstate()> pivot);
      if(i >= j){return j;}
      swap(i,j);
    }
  }
}

















