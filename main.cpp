#include <iostream>
#include <vector>
#include <algorithm>
#include "testobj.h"

int menu();
bool bynum();
bool byletter();

int main() {
  int answer;
  
  std::vector<int> first;
  std::vector<int> second (3,100);
  std::vector<int> third (second.begin(), second.end());
  std::vector<int> fourth (first);
  
  for(std::vector<int>::iterator it = third.begin(); it != third.end(); ++it){
    std::cout << ' '<< *it;
  }
  std::cout<<'\n';
  
  std::vector<testobj> test(1,testobj(5,'c'));
  test.push_back(testobj(11, 'l'));
  test.insert(test.begin(), testobj(2, 'f'));

  answer = menu();
  
  bool keepgoing = true;
  while(keepgoing == true){
    if(answer == 1){
      std::sort(test.begin(), test.end(), byletter);
      keepgoing = false;
    }
    else if(answer == 2){
      std::sort(test.begin(), test.end(), bynum);
      keepgoing =false;
    }
    else{
      std::cout<<"really?\n";
    }
}
  for(std::vector<testobj>::iterator ot = test.begin(); ot != test.end(); ++ot){
    std::cout << ' '<< ot->getnum() << ' ' << ot->getletter();
  }
  std::cout<<'\n';
 return 0;

}

int menu(){
  int i=0;
  std::cout<<"how would u like to sort?\n";
  std::cout<<"one for by letter, two for by number.\n";
  std::cin>>i;
  return i;
}

bool byletter(testobj elem1, testobj elem2){
  return elem1 > elem2;
}

bool bynum(testobj elem1, testobj elem2){
  return elem1 > elem2;
}

