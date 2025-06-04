#include "Cylinder.hpp"

Cylinder::Cylinder(GLUquadric *quad,
                   const float radiusTop,
                   const float radiusBottom,
                   const float height,
                   const int slices,
                   const int stacks)
  : radiusTop(radiusTop), radiusBottom(radiusBottom), height(height),
    slices(slices), stacks(stacks), quad(quad) {
}

void Cylinder::draw() const {
  glPushMatrix();

  gluCylinder(quad,
              radiusBottom,
              radiusTop,
              height,
              slices,
              stacks);

  glPopMatrix();
}
