
#include <iostream>
#include "testobj.h"



  testobj::testobj(){
    a = 0;
    b = ' ';
  }

  testobj::testobj(int c, char d){
    a = c;
    b = d;
  }
 
  char testobj::getletter(){
    return b;
  }

  int testobj::getnum(){
    return a;
  }

