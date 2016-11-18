#include<iostream>

using namespace std;

#include"curvebase.cpp"
#include"domain.cpp"

int main()
{
  xLine a = xLine(1.0,2.0,1.0);
  yLine b = yLine(1.0,2.0,2.0);
  xLine c = xLine(1.0,2.0,2.0);
  yLine d = yLine(1.0,2.0,1.0);

  Domain D = Domain(a,b,c,d);
  D.grid_generation(3,2);
  D.print();


  return 0;

}
