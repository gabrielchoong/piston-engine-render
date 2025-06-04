#include "Circle.hpp"

Circle::Circle(GLUquadric *quad,
               const float radius,
               const int slice)
  : radius(radius),
    slice(slice),
    quad(quad) {
}

void Circle::draw() const {
  // TODO: determine if inner radius needs to be dynamic
  gluDisk(quad, 0.0f, radius, slice, 1);
}
