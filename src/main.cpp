#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <memory>

#include "curve3D.h"
#include "circle.h"
#include "ellipse.h"
#include "helix.h"

#define PI  3.14159265358979323846

int main() {
    // Step 2: Populate container with random curves
    std::vector<std::shared_ptr<Curve3D>> curves;
    // curves.push_back(std::make_shared<Circle>(2.0));
    // curves.push_back(std::make_shared<Ellipse>(3.0, 2.0));
    // curves.push_back(std::make_shared<Helix>(1.0, 0.5));
    for (int i = 0; i < 1000; i++) {
        double random1 = (double)rand() / RAND_MAX;
        double random2 = (double)rand() / RAND_MAX;
        double random3 = (double)rand() / RAND_MAX;
        curves.push_back(std::make_shared<Circle>(random1));
        curves.push_back(std::make_shared<Ellipse>(random2, random3));
        curves.push_back(std::make_shared<Helix>(random3, random1));
    }
    // Step 3: Print coordinates of points and derivatives at t = PI/4
    double t = PI / 4;
   
    for (const auto& curve : curves) {
        std::vector<double> point = curve->getPoint(t);
        std::vector<double> derivative = curve->getDerivative(t);

        std::cout << "Curve Type: ";
        if (dynamic_cast<Circle*>(curve.get())) {
            std::cout << "Circle" << std::endl;
        } else if (dynamic_cast<Ellipse*>(curve.get())) {
            std::cout << "Ellipse" << std::endl;
        } else if (dynamic_cast<Helix*>(curve.get())) {
            std::cout << "Helix" << std::endl;
        }

        std::cout << "Point at t = PI/4: (" << point[0] << ", " << point[1] << ", " << point[2] << ")" << std::endl;
        std::cout << "Derivative at t = PI/4: (" << derivative[0] << ", " << derivative[1] << ", " << derivative[2] << ")" << std::endl;
        std::cout << std::endl;
    }

    // Step 4: Create a second container with circles from the first container
    std::vector<Circle*> circleContainer;
    for (const auto& curve : curves) {
        if (dynamic_cast<Circle*>(curve.get())) {
            circleContainer.push_back(static_cast<Circle*>(curve.get()));
        }
    }

    // Step 5: Sort the second container in ascending order of radii
    std::sort(circleContainer.begin(), circleContainer.end(), [](Circle* c1, Circle* c2) {
        return c1->getRadius() < c2->getRadius();
    });

    // Step 6: Compute the total sum of radii in the second container
    double sumOfRadii = 0.0;
    for (const auto& circle : circleContainer) {
        sumOfRadii += circle->getRadius();
    }

    std::cout << "Total sum of radii: " << sumOfRadii << std::endl;

    return 0;
}
