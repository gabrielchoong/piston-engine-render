#include "ConnectingRod.hpp"

#include "../shapes/Cuboid.hpp"

ConnectingRod::ConnectingRod(const Dimensions3f &dimensions)
  : dimensions(dimensions) {}

void ConnectingRod::draw() const {
  const Cuboid cuboid(dimensions);

  cuboid.draw();
}
