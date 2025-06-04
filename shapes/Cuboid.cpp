#include "Cuboid.hpp"
#include "DrawCuboid.hpp"

Cuboid::Cuboid(const Dimensions3f d)
  : dimensions(d) {
}

void Cuboid::draw() const {
  drawCuboid(dimensions);
}
