#ifndef DOMAIN_HPP
#define DOMAIN_HPP


#include <cstdio> 	// For writefile
#include <iostream>	
#include "curvebase.hpp"

class Domain {
  private:
    Curvebase * sides[4];
    int m_, n_;
    double *x_,*y_;	

    // Linear interpolation functions
    double phi1(double t);
    double phi2(double t);
  public:

    // CONSTRUCTOR
    Domain(Curvebase& s1, Curvebase& s2, Curvebase& s3, Curvebase& s4);

    // DESTRUCTOR
    ~Domain();

    // FUNCTIONS
    void grid_generation(int n, int m);
    void print();
    void writeFile();
};

#endif //DOMAIN_HPP
