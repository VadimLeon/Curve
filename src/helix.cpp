#include <cmath>

#include "curve3D.h"
#include "helix.h"

#define PI  3.14159265358979323846

//! Constructor for the Helix class
Helix::Helix(double rad, double dstep) : radius(rad), step(dstep) {}

//! Calculates the 3D point on the helix at parameter t
std::vector<double> Helix::getPoint(double t) const {
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = step * t / (2 * PI);
    return {x, y, z};
}

//! Calculates the first derivative (3D vector) on the helix at parameter t
std::vector<double> Helix::getDerivative(double t) const {
    double dx = -radius * std::sin(t);
    double dy = radius * std::cos(t);
    double dz = step / (2 * PI);
    return {dx, dy, dz};
}
