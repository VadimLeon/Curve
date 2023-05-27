#ifndef CLASS_ELLIPSE_H
#define CLASS_ELLIPSE_H

#include <vector>


//! Ellipse class derived from Curve3D
class Ellipse : public Curve3D {
public:
    //! Constructor for the Ellipse class
    Ellipse(double radX, double radY);

    //! Calculates the 3D point on the ellipse at parameter t
    std::vector<double> getPoint(double t) const override;

    //! Calculates the first derivative (3D vector) on the ellipse at parameter t
    std::vector<double> getDerivative(double t) const override;

private:
    double radiusX;
    double radiusY;
};


#endif // CLASS_ELLIPSE_H