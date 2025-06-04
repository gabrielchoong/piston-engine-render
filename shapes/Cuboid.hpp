#ifndef CUBOIDCLASS_HPP
#define CUBOIDCLASS_HPP

#include "../types.h"

class Cuboid {
public:
  Dimensions3f dimensions;

  explicit Cuboid(Dimensions3f dimensions);

  void draw() const;
};

#endif
