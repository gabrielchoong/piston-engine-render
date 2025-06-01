#include "cuboid.hpp"
#include "types.h"

void structure() {
  constexpr Dimensions3f dimensions = {0.2f, 0.3f, 0.5f};

  Cuboid(dimensions,
      Color3f{1.0f, 1.0f, 1.0f},
      Translate3f{0.0f, 0.0f, 0.0f},
      RotateY(0.0f),
      Scale3f{1.0f, 1.0f, 1.0f});
}
