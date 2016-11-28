
#include <iostream>
#include "point2.hpp"

//#include "newtsolve.cpp"

using namespace std;
int main(void){

  Point p(-1.0,1.0);
  p.print();

  double y;
  y = p.fquad2(0.5);
  cout << "y = " << y << endl;


  return 0;
}
