#include <GL/gl.h>

#include "../types.h"
#include "Piston.hpp"

void structure() {

  Piston p1(
      {0.0f, 0.0f, 0.0f},
      0.5f, 0.6f, 0.6f,
      0.1f, 0.2f, 0.2f,
      0.8f, 0.3f, 0.3f
    );

  glTranslatef(0.0f, 0.7f, 0.0f);
  p1.draw();
}
