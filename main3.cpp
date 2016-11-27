#include<iostream>

using namespace std;

#include"curvebase.cpp"
#include"domain.cpp"

int main()
{

  xQuad a = xQuad(-2,2,0,0,1);

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




  cout << "--------- NÄSTA KURVA --------------" << endl;
  // TESTA MED KURVAN VÄNSTER OM Y-AXELN
  xQuad aa = xQuad(-2,-2,0,-1.0,0);

  L = aa.integrate(-1,0);
  cout << "L = " << L << endl;
  L = aa.length;
  cout << "L = " << L << endl;

  Lhalf = 0.5*L;
  cout << "L*0.5 = " << Lhalf << endl;
  Lhalf = aa.integrate(-1,-0.5);
  cout << "Lhalf = " << Lhalf << endl;

  pp = aa.newtonsolve(-0.7,0.5);
  cout << "pp = " << pp << endl;
  LL = aa.integrate(-1,pp);
  cout << "LL = " << LL << endl;


  cout << "----------- Mer tester ----------" << endl;
  cout << a.dL2(0) << endl;
  cout << aa.dL2(0) << endl;

  cout << a.dyp2(0) << endl;
  cout << aa.dyp2(0) << endl;

  cout << "-------- Kolla a och b: ---------" << endl;
  cout << "a = " << a.print_a() << ", b = " << a.print_b() << endl;
  cout << "a = " << aa.print_a() << ", b = " << aa.print_b() << endl;

 
  xLine b = xLine(3,5,1);
  cout << "a = " << b.print_a() << endl;

   
  return 0;


}
