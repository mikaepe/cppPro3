
#include<cmath>
#include"integrate.cpp"

class Curvebase {
  protected:
    double a, b;		// start and end values for parameter
    int rev;			// orientation of curve
    double L;			// length of curve

    double xp(double p);	// x parametrized by user parameter
    double yp(double p);	// y parametrized by user parameter
    double dxp(double p);	// dxdp 
    double dyp(double p);	// dydp

    double integrate(double a, double b) {
      return integrate(a,b,1e-2*tol,&f);
    }

    double f(double p) {
      return sqrt( dxp(p)*dxp(p) + dyp(p)*dyp(p) );
    }
    
  public:
    Curvebase();
    double x(double s);		// x parametrized in grid coordinates
    double y(double s);		// y parametrized in grid coordinates

};


class Domain {
  /* "_" means local variable
   */

  public:
    Domain(const Curvebase&,const Curvebase&,const Curvebase&,const Curvebase&);
    
    void generate_grid(int n, int m);
    
    // fråga: om funktionen sitter i klassen ska det inte stå
    // void grid_generation(int n, int m){} ???
    void Domain::grid_generation(int n, int m){
      if ((n < 1) || (m < 1)) 
	std::cout << "exit (Failure)" << std::endl;

      if (n_ != 0) {			// or m_ != 0
	delete[] x_; delete[] y_;	// Varför? För att ta bort gamla saker om vi ger 
					// nya kurvor eller?
      }

      n_ = n; m_ = m;
      x_ = new double[(m+1)*(n+1)];
      y_ = new double[(n+1)*(m+1)];
      double h1 = 1.0/n; double h2 = 1.0/m;

      for (int i = 0; i<= n_; i++){
	for (int j = 0; j<= m_; j++){
	  x_[j+i*(m_+1)] = 
	    phi2(i*h1)*sides[3].x(j*h2) 	// left side
	    + phi1(i*h1)*sides[1].x(j*h2) 	// right side
	    + phi2(j*h2)*sides[0].x(i*h1)	// bottom side
	    + phi1(j*h2)*sides[2].x(i*h1)	// top side
	    - phi2(i*h1)*phi2(j*h2)*x(0,0)	// fixa x(00)
	    - phi1(i*h1)*phi2(j*h2)*x(1,0)	// fixa
	    - phi2(j*h2)*phi1(i*h1)*x(0,1)	// fixa
	    - phi1(i*h1)*phi2(j*h2)*x(1,1);	// fixa
	  
	  y_[j+i*(m_+1)] = 
	    phi2(i*h1)*sides[3].y(j*h2) 	// left side
	    + phi1(i*h1)*sides[1].y(j*h2) 	// right side
	    + phi2(j*h2)*sides[0].y(i*h1)	// bottom side
	    + phi1(j*h2)*sides[2].y(i*h1)	// top side
	    - phi2(i*h1)*phi2(j*h2)*y(0,0)	// fixa x(00)
	    - phi1(i*h1)*phi2(j*h2)*y(1,0)	// fixa
	    - phi2(j*h2)*phi1(i*h1)*y(0,1)	// fixa
	    - phi1(i*h1)*phi2(j*h2)*y(1,1);	// fixa
	}
    }
  
  private:
    Curvebase *sides[4];
    int m_=0,n_=0;
    double *x_,*y_;			// x,y-coordinates, "underscore = internal"

    // Linear interpolation functions
    double phi1(double t) {return t;}
    double phi2(double t) {return 1-t;}

  // etc...
};


