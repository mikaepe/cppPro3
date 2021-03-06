#include<iostream>

using namespace std;

#include"curvebase.cpp"
#include"domain.cpp"

int main()
{
  /*
  xLine a = xLine(1.0,2.0,1.0);
  yLine b = yLine(1.0,2.0,2.0);
  xLine c = xLine(1.0,2.0,2.0);
  yLine d = yLine(1.0,2.0,1.0);
  */

  fxCurve a = fxCurve(-10,5);
  yLine b = yLine(0,3,5);
  xLine c = xLine(-10,5,3);
  yLine d = yLine(0,3,-10);

  Domain D = Domain(a,b,c,d);
  D.grid_generation(10,10);
  //D.print();
  D.writeFile();


  /*
  xQuad yy = xQuad(0.0,1.0,1.0,1.0,2.0);
  // y = 0+x+1, x in [1,2]
  double L;
  L = yy.integrate(1.0,2.0);
  // length should be sqrt(2):
  cout << "L = " << L << endl;

  xQuad yy2 = xQuad(-1.0,1.0,0.0,0.0,1.0);
  // y = -x^2 + x = -x(x-1), x in [1,2]
  // length should be 1.1478 (from wolfram alpha)
  L = yy2.integrate(0,1);
  cout << "L = " << L << endl;
  
  // solutions to y(x) = 0 given by y = 0 and y = 1:
  double sol;
  sol = yy2.newtonsolve(0.1);
  cout << "root1 = " << sol << endl;
  sol = yy2.newtonsolve(1.80);
  cout << "root2 = " << sol << endl;

  */
    
  return 0;


}
