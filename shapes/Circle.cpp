#include "Circle.hpp"

Circle::Circle(GLUquadric *quad,
               const float radius,
               const int slices)
  : radius(radius),
    slices(slices),
    quad(quad) {
}

void Circle::draw() const {
  gluDisk(quad,
          0.0f,
          radius,
          slices,
          1);
}
