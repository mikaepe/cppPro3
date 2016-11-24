#ifndef CPPPRO3_XLINE_H
#define CPPPRO3_XLINE_H

#include "curvebase.h"

class xLine: public Curvebase{
public:
    xLine(double xi, double xf, double y0){
        xStart = xi;
        xStop = xf;		//TODO use initialization lists instead??
        yConst = y0;
        length = xf-xi;
    }
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization

protected:
    double xStart;
    double xStop;
    double yConst;
    double xp(double p) { return p; }
    double yp(double p) { return yConst; }
    double dxp(double p) { return 1; }
    double dyp(double p) { return 0; }
    double integrate(double a, double b); //arc length integral
};

#endif
