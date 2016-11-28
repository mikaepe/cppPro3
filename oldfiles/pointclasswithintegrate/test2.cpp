
#include<iostream>

using namespace std;




// the function using the function pointers:
double max(double (*fptr)(void*, double), void* context) {
  double max = 0;
  double x,y;
  for (int i = 100; i>0; i--) {
    x = 1.0/i;
    y = fptr(context,x);
    if (y > max) {
      max = y;
    }
  }

  return max;
 
  //fptr(context, 17, 42);
}

/*
double non_member(void*, double t) {
  std::cout << "non_member, t = " << t << std::endl;
}
*/

class Point {
  private:
    double x;
    double y;
  public:
    Point(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) {}
    double X() const {return x;}
    double Y() const {return y;}
    void print() {
      std::cout << "[" << x << "," << y << "]" << std::endl;
    }

    double member(double t) {
      return x*t*t + y*t;
    }

};

double forwarder(void* context, double t) {
    static_cast<Point*>(context)->member(t);
}

int main() {
    //max(&non_member, 0);
    Point object(-1.0,1.0);
    double m;
    m = max(&forwarder, &object);
    cout << "max = " << m << endl;




    return 0;
}
