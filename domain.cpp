#include <cstdio>	// for writeFile()
#include <iostream>	

#include "domain.hpp"
#include "curvebase.hpp"

/*
 * .cpp-file for class domain. See also domain.hpp.
 * Constructor: Input is 4 curvebase objects
 * 		Setting m_ = n_ = 0 and 
 */


// CONSTRUCTOR
Domain::Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4) {
  sides[0] = &s1;
  sides[1] = &s2;
  sides[2] = &s3;
  sides[3] = &s4;

  m_ = n_ = 0;
  x_ = y_ = NULL;
  xLo = xRi = xTo = xLe = NULL;
  yLo = yRi = yTo = yLe = NULL;
}

// DESTRUCTOR
Domain::~Domain() {
  if (m_ > 0) {
    delete [] x_;
    delete [] y_;
    
    delete [] xLo;
    delete [] xRi;
    delete [] xTo;
    delete [] xLe;

    delete [] yLo;
    delete [] yRi;
    delete [] yTo;
    delete [] yLe;
  }
}

// MEMBER FUNCTIONS
double Domain::phi1(double t) { return t; }
double Domain::phi2(double t) { return 1.0-t; }

void Domain::grid_generation(int n, int m) {
  if ((n < 1) || (m < 1)) {
    std::cout << "Warning: Non positive grid size." << std::endl; 
    // TODO fixa nån bättre felhantering
    std::cout << "No grid generated" << std::endl;
    
    return;
  }
  std::cout << "hej???" << std::endl;
  						// TODO kolla att x1(0) = x4(0) osv..

  if (n != 0) {					// or m != 0
    delete[] x_; 
    delete[] y_;

    delete[] xLo;
    delete[] xRi;
    delete[] xTo;
    delete[] xLe;

    delete[] yLo;
    delete[] yRi;
    delete[] yTo;
    delete[] yLe;
  }

  n_ = n; 
  m_ = m;

  // INSTEAD OF COMPUTING x_  (n+1)*(m+1) times, compute
  // xLo, xRi, xTo, xLe once only.

  xLo = new double[n_+1];
  xRi = new double[m_+1];
  xTo = new double[n_+1];
  xLe = new double[m_+1];

  yLo = new double[n_+1];
  yRi = new double[m_+1];
  yTo = new double[n_+1];
  yLe = new double[m_+1];


  double h1= 1.0/n; double h2 = 1.0/m;

  for (int i=0; i <= n_; i++) {
    xLo[i] = sides[0]->x(i*h1);
    xTo[i] = sides[2]->x(i*h1);
    
    yLo[i] = sides[0]->y(i*h1);
    yTo[i] = sides[2]->y(i*h1);

  }
  for (int j=0; j <= m_; j++) {
    xRi[j] = sides[1]->x(j*h2);
    xLe[j] = sides[3]->x(j*h2);
    
    yRi[j] = sides[1]->y(j*h2);
    yLe[j] = sides[3]->y(j*h2);
  }


  x_ = new double[(n_+1)*(m_+1)];
  y_ = new double[(n_+1)*(m_+1)];



  for (int i = 0; i <= n_; i++) {

    for (int j = 0; j <= m_; j++) {

      x_[j+i*(m_+1)] = 
	phi2(i*h1)*xLe[j] //sides[3]->x(j*h2) 		// left side
	+ phi1(i*h1)*xRi[j] //sides[1]->x(j*h2) 		// right side
	+ phi2(j*h2)*xLo[i] //sides[0]->x(i*h1)		// bottom side
	+ phi1(j*h2)*xTo[i] //sides[2]->x(i*h1)		// top side
	- phi2(i*h1)*phi2(j*h2)*xLo[0] //sides[0]->x(0)	// lower left 
	- phi1(i*h1)*phi2(j*h2)*xLo[n_] //sides[0]->x(1)	// lower right
	- phi2(i*h1)*phi1(j*h2)*xTo[0] //sides[2]->x(0)	// top left
	- phi1(i*h1)*phi1(j*h2)*xTo[n_]; //sides[2]->x(1);	// top right
	
      y_[j+i*(m_+1)] = 
	phi2(i*h1)*yLe[j] //sides[3]->y(j*h2) 		// left side
	+ phi1(i*h1)*yRi[j] //sides[1]->y(j*h2) 		// right side
	+ phi2(j*h2)*yLo[i] //sides[0]->y(i*h1)		// bottom side
	+ phi1(j*h2)*yTo[i] // sides[2]->y(i*h1)		// top side
	- phi2(i*h1)*phi2(j*h2)*yLo[0] //sides[0]->y(0)	// fixa x(00)
	- phi1(i*h1)*phi2(j*h2)*yLo[n_] //sides[0]->y(1)	// fixa
	- phi2(i*h1)*phi1(j*h2)*yTo[0] //sides[2]->y(0)	// fixa
	- phi1(i*h1)*phi1(j*h2)*yTo[n_];// sides[2]->y(1);	// fixa
    }
  }
}

void Domain::print() {
  for (int i = 0; i < (n_+1)*(m_+1); i++) {
    std::cout << "[" << x_[i] << "," << y_[i] << "]" << std::endl;
  }
}

void Domain::writeFile(){
  if (n_ < 1 || m_ < 1) {
    std::cout << "No grid available for writeFile()" << std::endl;
    return;
  }
  FILE *fp;
  fp =fopen("outfile.bin","wb");
  fwrite(x_,sizeof(double),(n_+1)*(m_+1),fp);
  fwrite(y_,sizeof(double),(n_+1)*(m_+1),fp);
  fclose(fp);
}

