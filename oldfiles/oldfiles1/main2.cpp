#include<iostream>

using namespace std;

#include"curvebase.cpp"
#include"domain.cpp"

int main()
{

  //fxCurve a = fxCurve(-10,5);

  xQuad a = xQuad(-2,2,0,0,1);

  //yLine b = yLine(0,1,0);
  //xLine c = xLine(-1,0,1);
  //yLine d = yLine(0,1,-1);

  double L;
  L = a.integrate(0,1);
  cout << "L = " << L << endl;
  L = a.length;
  cout << "L = " << L << endl;

  double Lhalf;
  Lhalf = 0.5*L;
  cout << "L*0.5 = " << Lhalf << endl;
  Lhalf = a.integrate(0,0.5);
  cout << "Lhalf = " << Lhalf << endl;

  double pp;
  pp = a.newtonsolve(0.3,0.5);
  cout << "pp = " << pp << endl;
  double LL;
  LL = a.integrate(0,pp);
  cout << "LL = " << LL << endl;

  /*
  Domain D = Domain(a,b,c,d);
  D.grid_generation(4,4);
  //D.print();
  D.writeFile();
  */


 

   
  return 0;


}
