#ifndef CLASS_HELIX_H
#define CLASS_HELIX_H


#include <vector>

//! 3D Helix class derived from Curve3D
class Helix : public Curve3D {
public:
    //! Constructor for the Helix class
    Helix(double radius, double step);

    //! Calculates the 3D point on the helix at parameter t
    std::vector<double> getPoint(double t) const override;

    //! Calculates the first derivative (3D vector) on the helix at parameter t
    std::vector<double> getDerivative(double t) const override;

private:
    double radius;
    double step;
};


#endif // CLASS_HELIX_H