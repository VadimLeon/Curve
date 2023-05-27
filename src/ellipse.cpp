#include <cmath>

#include "curve3D.h"
#include "ellipse.h"


//! Constructor for the Ellipse class
Ellipse::Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {}

//! Calculates the 3D point on the ellipse at parameter t
std::vector<double> Ellipse::getPoint(double t) const {
    double x = radiusX * std::cos(t);
    double y = radiusY * std::sin(t);
    double z = 0.0;
    return { x, y, z };
}

//! Calculates the first derivative (3D vector) on the ellipse at parameter t
std::vector<double> Ellipse::getDerivative(double t) const {
    double dx = -radiusX * std::sin(t);
    double dy = radiusY * std::cos(t);
    double dz = 0.0;
    return { dx, dy, dz };
}
