#ifndef CYLINDER_HPP
#define CYLINDER_HPP

#include <GL/freeglut_std.h>

class Cylinder {
public:
  Cylinder(GLUquadric *quad,
           float cylinderTopRadius,
           float cylinderBottomRadius,
           float cylinderHeight,
           int slice,
           int stack);

  void draw() const;

private:
  float cylinderTopRadius, cylinderBottomRadius, cylinderHeight;
  int slice, stack;
  GLUquadric *quad;
};

#endif
