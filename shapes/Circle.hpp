#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <GL/freeglut_std.h>

class Circle {
public:
  Circle(GLUquadric *quad,
         float radius,
         int slice);

  void draw() const;

private:
  float radius;
  int slice;
  GLUquadric *quad;
};

#endif
