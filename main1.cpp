#include<iostream>

using namespace std;

#include "curvebase.hpp"
#include "xline.hpp"
#include "yline.hpp"
//#include "xquad.hpp"
#include "fxcurve.hpp"
#include "domain.hpp"


int main()
{

  
  fxCurve a = fxCurve(-10,5);	// f(x) from -10 to 5
  yLine b = yLine(0,3,5);	// vertical line from 0 to 3 at x=5
  xLine c = xLine(-10,5,3);	// horiz. line from -10 to 5 at y=3
  yLine d = yLine(0,3,-10);	// vertical line from 0 to 3 at x=-10
 

  /*
  xQuad a = xQuad(-1,-1,0,-1,0);// y=-x^2-x from x=-1 to x=0
  yLine b = yLine(0,1,0);
  xLine c = xLine(-1,0,1);
  yLine d = yLine(0,1,-1);
  */

  Domain D = Domain(a,b,c,d);	// Domain object
  D.grid_generation(50,20);	// Generate the grid on the domain

  //D.print();
  D.writeFile();		// Write to binary file (for matlab)

  
  return 0;


}
