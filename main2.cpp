#include<iostream>

using namespace std;

#include"curvebase.cpp"
#include"domain.cpp"

int main()
{

  //fxCurve a = fxCurve(-10,5);
  xQuad a = xQuad(0.2,1.0,-10,-10,5);
  yLine b = yLine(0,3,5);
  xLine c = xLine(-10,5,3);
  yLine d = yLine(0,3,-10);

  Domain D = Domain(a,b,c,d);
  D.grid_generation(5,5);
  D.print();
  D.writeFile();


  //double y;
  //y = a.yyp(-6);
  //cout << y << endl;

   
  return 0;


}
