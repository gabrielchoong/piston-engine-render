#include "Cylinder.hpp"

Cylinder::Cylinder(GLUquadric* quad,
                   float radiusTop,
                   float radiusBottom,
                   float height,
                   int slices,
                   int stacks)
                     : radiusTop(radiusTop), radiusBottom(radiusBottom), height(height),
                       slices(slices), stacks(stacks), quad(quad) {}

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