

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
	  x_[j+i*(m_+1)] = phi1(i*h1)*sides[3]->x(j*h2)
	    + phi2*sides[1]->x(j*h2)
	    + term3 
	    + term4 - corr1 -corr2 - corr3 - corr4;
	  y_[...] = .... ;
    }
  
  private:
    Curvebase *sides[4];
    int m_=0,n_=0;
    double *x_,*y_;			// x,y-coordinates, "underscore = internal"

    // 

  // etc...
};


