#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../types.h"

#include <GL/freeglut_std.h>

class Circle {
public:
  Circle(GLUquadric* quad,
         float radius,
         int slices,
         Rotate4f rotation,
         Translate3f translation);

  void draw() const;

private:
  float radius;
  int slices;
  Rotate4f rotation;
  Translate3f translation;
  GLUquadric* quad;
};

#endif
