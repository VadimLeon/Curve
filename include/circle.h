#ifndef CLASS_CIRCLE_H
#define CLASS_CIRCLE_H

#include <vector>

//! Circle class derived from Curve3D
class Circle : public Curve3D {
public:
    //! Constructor for the Circle class
    Circle(double radius);

    //! Calculates the 3D point on the circle at parameter t
    std::vector<double> getPoint(double t) const override;

    //! Calculates the first derivative (3D vector) on the circle at parameter t
    std::vector<double> getDerivative(double t) const override;

    //! Returns the radius of the circle
    double getRadius();

private:
    double radius;
};


#endif // CLASS_CIRCLE_H