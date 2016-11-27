#include<iostream>

using namespace std;

#include"curvebase.cpp"
#include"domain.cpp"

int main()
{

  //fxCurve a = fxCurve(-10,5);

  xQuad a = xQuad(-2,2,0,0,1);
  yLine b = yLine(0,1,1);
  xLine c = xLine(0,1,1);
  yLine d = yLine(0,1,0);


  double L;
  L = a.integrate(0,1);
  cout << "L = " << L << endl;

/*
  xQuad a = xQuad(-2,-2,0,-1,0);
  yLine b = yLine(0,1,0);
  xLine c = xLine(-1,0,1);
  yLine d = yLine(0,1,-1);

  L = a.integrate(-1,0);

  cout << "L = " << L << endl;
*/

  Domain D = Domain(a,b,c,d);
  D.grid_generation(4,4);
  //D.print();
  D.writeFile();


 

   
  return 0;


}
