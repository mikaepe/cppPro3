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

// curves for lines with constant y
// konstruktor: start-x, slut-x, konstant-y
// overwrite integrate, xp, yp, dxp, dyp, x(s), y(s)
class xLine: public Curvebase{
public:
    xLine(double xi, double xf, double y0){
        xStart = xi;
        xStop = xf;
        yConst = y0;
        length = xf-xi;
    }
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization
protected:
    double xStart;
    double xStop;
    double yConst;
    double xp(double p){
        return p;
    };
    double yp(double p){
        return yConst;
    };
    double dxp(double p){
        return 1;
    };
    double dyp(double p){
        return 0;
    };
    double integrate(double a, double b); //arc length integral
};

double xLine::integrate(double a, double b){
    return (b-a);
};

// do arc length parametrization
double xLine::y(double s){
    return yConst;
};

// do arc length parametrization
double xLine::x(double s){
    return xStart+s*length;
};


// curve for lines with constant x
// konstruktor: start-y, slut-y, konstant-x
// overwrite integrate, xp, yp, dxp, dyp, x(s), y(s)
class yLine: public Curvebase{
public:
    yLine(double yi, double yf, double x0){
        yStart = yi;
        yStop = yf;
        xConst = x0;
        length = yf-yi;
    }
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization
protected:
    double yStart;
    double yStop;
    double xConst;
    double xp(double p){
        return xConst;
    };
    double yp(double p){
        return p;
    };
    double dxp(double p){
        return 0;
    };
    double dyp(double p){
        return 1;
    };
    double integrate(double a, double b); //arc length integral
};

double yLine::integrate(double a, double b){
    return (b-a);
};

// do arc length parametrization
double yLine::x(double s){
    return xConst;
};

// do arc length parametrization
double yLine::y(double s){
    return yStart+s*length;
};


class fCurve: public Curvebase{
    // konstruktor: start-x, skift-x, slut-z
    // overwrite xp, yp, dxp, dyp
};