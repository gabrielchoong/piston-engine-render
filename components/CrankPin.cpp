#include "CrankPin.hpp"

#include "../shapes/Cylinder.hpp"

CrankPin::CrankPin(const float crankPinTopRadius,
                   const float crankPinBottomRadius,
                   const float crankPinHeight,
                   const int slice,
                   const int stack)
  : crankPinTopRadius(crankPinTopRadius),
    crankPinBottomRadius(crankPinBottomRadius),
    crankPinHeight(crankPinHeight),
    slice(slice),
    stack(stack) {}

void CrankPin::draw() const {
  GLUquadric *quad = gluNewQuadric();

  const Cylinder cylinder(quad,
                          crankPinTopRadius,
                          crankPinBottomRadius,
                          crankPinHeight,
                          slice,
                          stack);

  cylinder.draw();

  gluDeleteQuadric(quad);
}
