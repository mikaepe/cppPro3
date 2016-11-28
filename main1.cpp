#include<iostream>

using namespace std;

#include "curvebase.hpp"
#include "domain.hpp"

int main()
{

  fxCurve a = fxCurve(-10,5);
  yLine b = yLine(0,3,5);
  xLine c = xLine(-10,5,3);
  yLine d = yLine(0,3,-10);


  cout << "här går det bra" << endl;
  /*
  xQuad a = xQuad(-1,-1,0,-1,0);
  yLine b = yLine(0,1,0);
  xLine c = xLine(-1,0,1);
  yLine d = yLine(0,1,-1);
  */

  Domain D = Domain(a,b,c,d);
  D.grid_generation(50,20);
  //D.print();
  D.writeFile();

  
  return 0;


}
