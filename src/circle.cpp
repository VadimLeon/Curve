#include <cmath>

#include "curve3D.h"
#include "circle.h"

//! Constructor for the Circle class
Circle::Circle(double rad) : radius(rad) {}

//! Calculates the 3D point on the circle at parameter t
std::vector<double> Circle::getPoint(double t) const {
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = 0.0;
    return {x, y, z};
}

//! Calculates the first derivative (3D vector) on the circle at parameter t
std::vector<double> Circle::getDerivative(double t) const {
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    double dz = 0.0;
    return {dx, dy, dz};
}

//! Returns the radius of the circle
double Circle::getRadius() { return radius; }
