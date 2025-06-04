#include "Cuboid.hpp"
#include "DrawCuboid.hpp"

Cuboid::Cuboid(const Dimensions3f dimensions)
  : dimensions(dimensions) {
}

void Cuboid::draw() const {
  drawCuboid(dimensions);
}
