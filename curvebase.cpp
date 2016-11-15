class Curvebase {
protected:
    double pmin;
    double pmax;
    double a;
    double b;
    int rev; // orientation of the curve
    double length;

    virtual double xp(double p) = 0;
    virtual double yp(double p) = 0;
    virtual double dxp(double p) = 0;
    virtual double dyp(double p) = 0;
    double integrate(double a, double b); //arc length integral

public:
    Curvebase(); //constructor
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization

};

// use integration from project 1 to do arc length integration (see p 10 inheritance slides)
double Curvebase::integrate(double a, double b){
    return 0;
}

// do arc length parametrization
// compute p by Newtons method (see lecture 06) and return xp(p)
double Curvebase::x(double s){
    return 0;
}

// do arc length parametrization
// compute p by Newtons method (see lecture 06) and return yp(p)
double Curvebase::y(double s){
    return 0;
}

class xLine: public Curvebase{
    // konstruktor: start-x, slut-x, konstant-y
    // overwrite integrate, xp, yp, dxp, dyp, x(s), y(s)
};

class yLine: public Curvebase{
    // konstruktor: start-y, slut-y, konstant-x
    // overwrite integrate, xp, yp, dxp, dyp, x(s), y(s)
};

class fCurve: public Curvebase{
    // konstruktor: start-x, skift-x, slut-z
    // overwrite xp, yp, dxp, dyp
};