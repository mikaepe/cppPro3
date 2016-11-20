
#include"asi.hpp"
#include<cmath>

// function declarations	::	::	::

double iSimpson(double a, double b, fctnPtr f);
double mid(double x, double y);
double i2Simpson(double a, double b, fctnPtr f);
double asi(double a, double b, double tol, fctnPtr f);

// function definitions	::	::	::	::


/* function asi: Adaptive Simpson Integration between a and b with 
 * tolerance tol. Use a tree instead of recursion. The root is node 
 * number 1, and each node k has at most 2 children:
 * - node 2k (the left one)
 * - node 2k+1 (the right one)
 * In the left child b is changed to mid(a,b) and tol=tol/2
 * In the right child a is changed to mid(a,b) and tol=tol/2
 * The parent of a node is given by floor(0.5*node) if node!=1
 */
double asi(double a, double b, double tol, fctnPtr f) 
{
    double I = 0, I1, I2, errest;
    int node = 1;

    while (true) {
        I1 = iSimpson(a, b, f);
        I2 = i2Simpson(a, b, f);
        errest = std::abs(I1 - I2);
        if (errest < 15 * tol) { //if leaf
            I += I2;
            // while uneven node: go up until first even node
            while (node % 2 != 0) {
                if (node == 1) {
                    return I; // return if we are back in the root again
                }
                node = std::floor(0.5 * node); //TODO behövs floor här??
                a = 2 * a - b;
                tol *= 2;
            }
            // first even node: go one node up - go to the right child 
            node = 0.5 * node;
            b = 2 * b - a;
            node = 2 * node + 1;
            a = mid(a,b);
        }            
        // If not a leaf: go to the left child
        else {
            node *= 2;
            b = mid(a,b);
            tol *= 0.5;
        }
    }
    return I;
}

// Simpson of left half interval and right half interval of (a,b)
double i2Simpson(double a, double b, fctnPtr f)
{
  return iSimpson(a,mid(a,b),f) + iSimpson(mid(a,b),b,f);
}

// returns the midpoint of x & y
double mid(double x, double y)
{
  return 0.5*(x+y);
}

// Simpson quadrature between a and b
double iSimpson(double a, double b, fctnPtr f)
{
  return ((b-a)/6.0)*(f(a)+4.0*f(0.5*(a+b)) + f(b));
}

