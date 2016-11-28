#include<cstdio>
#include <iostream>


class Domain {
  /* "_" means local variable
   */

  
  private:
    Curvebase * sides[4];
    int m_, n_;
    double *x_,*y_;			// x,y-coordinates, "underscore = internal"

    // Linear interpolation functions
    double phi1(double t) {return t;}
    double phi2(double t) {return 1-t;}



  public:

    // CONSTRUCTOR
    Domain(Curvebase& s1,
	Curvebase& s2,
	Curvebase& s3,
	Curvebase& s4) {
      sides[0] = &s1;
      sides[1] = &s2;
      sides[2] = &s3;
      sides[3] = &s4;

      m_ = n_ = 0;
      x_ = y_ = NULL;
    };

    // DESTRUCTOR
    ~Domain() {
      if (m_ > 0) {
	delete [] x_;
	delete [] y_;
      }
    }
    
    
    void grid_generation(int n, int m){
      if ((n < 1) || (m < 1)) 
	std::cout << "exit (Failure)" << std::endl;

      if (n_ != 0) {			// or m_ != 0
	delete[] x_; delete[] y_;	// Varför? För att ta bort gamla saker om vi ger 
					// nya kurvor eller?
      }

      n_ = n; m_ = m;
      x_ = new double[(n_+1)*(m_+1)];
      y_ = new double[(n_+1)*(m_+1)];
      double h1 = 1.0/n; double h2 = 1.0/m;

      for (int i = 0; i<= n_; i++){
	for (int j = 0; j<= m_; j++){
	  std::cout << ":::::::: sx = " << i*h1 << std::endl;
	  std::cout << ":::::::: sy = " << j*h2 << std::endl;	// TODO ta bort
	
	  x_[j+i*(m_+1)] = 
	    phi2(i*h1)*sides[3]->x(j*h2) 	// left side
	    + phi1(i*h1)*sides[1]->x(j*h2) 	// right side
	    + phi2(j*h2)*sides[0]->x(i*h1)	// bottom side
	    + phi1(j*h2)*sides[2]->x(i*h1)	// top side
	    - phi2(i*h1)*phi2(j*h2)*sides[0]->x(0)	// fixa x(00)
	    - phi1(i*h1)*phi2(j*h2)*sides[0]->x(1)	// fixa
	    - phi2(i*h1)*phi1(j*h2)*sides[2]->x(0)	// fixa
	    - phi1(i*h1)*phi1(j*h2)*sides[2]->x(1);	// fixa
	  
	  y_[j+i*(m_+1)] = 
	    phi2(i*h1)*sides[3]->y(j*h2) 	// left side
	    + phi1(i*h1)*sides[1]->y(j*h2) 	// right side
	    + phi2(j*h2)*sides[0]->y(i*h1)	// bottom side
	    + phi1(j*h2)*sides[2]->y(i*h1)	// top side
	    - phi2(i*h1)*phi2(j*h2)*sides[0]->y(0)	// fixa x(00)
	    - phi1(i*h1)*phi2(j*h2)*sides[0]->y(1)	// fixa
	    - phi2(i*h1)*phi1(j*h2)*sides[2]->y(0)	// fixa
	    - phi1(i*h1)*phi1(j*h2)*sides[2]->y(1);	// fixa
	}
      }
    }

      void print() {
	for (int i = 0; i < (n_+1)*(m_+1); i++) {
	  std::cout << "[" << x_[i] << "," << y_[i] << "]" << std::endl;
	}
      }

    void writeFile(){
        FILE *fp;
        fp =fopen("outfile.bin","wb");
        fwrite(x_,sizeof(double),(n_+1)*(m_+1),fp);
        fwrite(y_,sizeof(double),(n_+1)*(m_+1),fp);
        fclose(fp);
    }
};


