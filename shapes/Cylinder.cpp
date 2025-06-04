#include "Cylinder.hpp"

Cylinder::Cylinder(GLUquadric *quad,
                   const float cylinderTopRadius,
                   const float cylinderBottomRadius,
                   const float cylinderHeight,
                   const int slice,
                   const int stack)
  : cylinderTopRadius(cylinderTopRadius),
    cylinderBottomRadius(cylinderBottomRadius),
    cylinderHeight(cylinderHeight),
    slice(slice),
    stack(stack),
    quad(quad) {
}

void Cylinder::draw() const {
  glPushMatrix();

  gluCylinder(quad,
              cylinderBottomRadius,
              cylinderTopRadius,
              cylinderHeight,
              slice,
              stack);

  glPopMatrix();
}
