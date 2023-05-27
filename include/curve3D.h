#ifndef CLASS_CURVE3D_H
#define CLASS_CURVE3D_H

#include <vector>


//! Base abstract class for 3D curves
class Curve3D {
public:
    virtual ~Curve3D() {}

    //! Returns the 3D point on the curve at parameter t
    virtual std::vector<double> getPoint(double t) const = 0;

    //! Returns the first derivative (3D vector) on the curve at parameter t
    virtual std::vector<double> getDerivative(double t) const = 0;
};


#endif // CLASS_CURVE3D_H