#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <GL/freeglut_std.h>

class Circle {
public:
  Circle(GLUquadric *quad,
         float radius,
         int slices);

  void draw() const;

private:
  float radius;
  int slices;
  GLUquadric *quad;
};

#endif
