#include <iostream>


double phi1(double t) {return t;}
double phi2(double t) {return 1-t;}


using namespace std;
int main(void){
  double t = 0.423;

  double x,y;
  x = phi1(t);
  y = phi2(t);

  cout << "t = " << t << endl;
  cout << "phi1 = " << x << endl;
  cout << "phi2 = " << y << endl;

  return 0;
}
