#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "types.h"

void drawCuboid(const Dimensions3f& dimensions);

void Cuboid(const Dimensions3f& dimensions,
            const Color3f& color = {1.0f, 1.0f, 1.0f},
            const Translate3f& position = {0.0f, 0.0f, 0.0f},
            const Rotate4f& rotation = {0.0f, {0.0f, 1.0f, 0.0f}},
            const Scale3f& scale = {1.0f, 1.0f, 1.0f});

inline Rotate4f RotateX(const float angle) {
  return Rotate4f{angle, {1.0f, 0.0f, 0.0f}};
}

inline Rotate4f RotateY(const float angle) {
  return Rotate4f{angle, {0.0f, 1.0f, 0.0f}};
}

inline Rotate4f RotateZ(const float angle) {
  return Rotate4f{angle, {0.0f, 0.0f, 1.0f}};
}


#endif
