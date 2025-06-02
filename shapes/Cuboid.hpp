#ifndef CUBOIDCLASS_HPP
#define CUBOIDCLASS_HPP

#include "../types.h"

class Cuboid {
public:
  Dimensions3f dimensions;
  Translate3f translate;
  Rotate4f rotation;
  Scale3f scale;

  Cuboid(Dimensions3f d, Translate3f t, Rotate4f r, Scale3f s);
  void draw() const;
};

void drawCuboid(const Dimensions3f& dimensions);

#endif
