#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include <GL/freeglut_std.h>

class Cylinder {
public:
  Cylinder(GLUquadric* quad,
           float radiusTop,
           float radiusBottom,
           float height,
           int slices,
           int stacks);

  void draw() const;

private:
  float radiusTop, radiusBottom, height;
  int slices, stacks;
  GLUquadric* quad;
};

#endif
