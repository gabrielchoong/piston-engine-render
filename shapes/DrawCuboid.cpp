#include "DrawCuboid.hpp"

#include <GL/gl.h>

void drawCuboid(const Dimensions3f &dimensions) {
  float x;
  float y;
  const float z = y = x = 0.0f;

  const float h = dimensions.height;
  const float l = dimensions.length;
  const float w = dimensions.width;

  // front
  glBegin(GL_QUADS);
  glVertex3f(x, y, z);
  glVertex3f(x + l, y, z);
  glVertex3f(x + l, y + h, z);
  glVertex3f(x, y + h, z);
  glEnd();

  // back
  glBegin(GL_QUADS);
  glVertex3f(x, y, z + w);
  glVertex3f(x + l, y, z + w);
  glVertex3f(x + l, y + h, z + w);
  glVertex3f(x, y + h, z + w);
  glEnd();

  // bottom
  glBegin(GL_QUADS);
  glVertex3f(x, y, z);
  glVertex3f(x, y, z + w);
  glVertex3f(x + l, y, z + w);
  glVertex3f(x + l, y, z);
  glEnd();

  // top
  glBegin(GL_QUADS);
  glVertex3f(x, y + h, z);
  glVertex3f(x, y + h, z + w);
  glVertex3f(x + l, y + h, z + w);
  glVertex3f(x + l, y + h, z);
  glEnd();

  // left
  glBegin(GL_QUADS);
  glVertex3f(x, y, z);
  glVertex3f(x, y + h, z);
  glVertex3f(x, y + h, z + w);
  glVertex3f(x, y, z + w);
  glEnd();

  // right
  glBegin(GL_QUADS);
  glVertex3f(x + l, y, z);
  glVertex3f(x + l, y + h, z);
  glVertex3f(x + l, y + h, z + w);
  glVertex3f(x + l, y, z + w);
  glEnd();
}
