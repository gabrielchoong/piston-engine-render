#include "Cuboid.hpp"

#include <GL/glut.h>

Cuboid::Cuboid(Dimensions3f d, Translate3f t, Rotate4f r, Scale3f s)
  : dimensions(d), translate(t), rotation(r), scale(s) {}

void Cuboid::draw() const {
  glPushMatrix();

  glTranslatef(translate.x, translate.y, translate.z);
  glRotatef(rotation.angle, rotation.axis.x, rotation.axis.y, rotation.axis.z);
  glScalef(scale.x, scale.y, scale.z);

  drawCuboid(dimensions);

  glPopMatrix();
}

void drawCuboid(const Dimensions3f& dimensions) {
  float x;
  float y;
  float z = y = x = 0.0f;

  float h = dimensions.height;
  float l = dimensions.length;
  float w = dimensions.width;

  // front
  glBegin(GL_QUADS);
  glVertex3f(x    , y    , z);
  glVertex3f(x + l, y    , z);
  glVertex3f(x + l, y + h, z);
  glVertex3f(x    , y + h, z);
  glEnd();

  // back
  glBegin(GL_QUADS);
  glVertex3f(x    , y    , z + w);
  glVertex3f(x + l, y    , z + w);
  glVertex3f(x + l, y + h, z + w);
  glVertex3f(x    , y + h, z + w);
  glEnd();

  // bottom
  glBegin(GL_QUADS);
  glVertex3f(x    , y, z    );
  glVertex3f(x    , y, z + w);
  glVertex3f(x + l, y, z + w);
  glVertex3f(x + l, y, z    );
  glEnd();

  // top
  glBegin(GL_QUADS);
  glVertex3f(x    , y + h, z    );
  glVertex3f(x    , y + h, z + w);
  glVertex3f(x + l, y + h, z + w);
  glVertex3f(x + l, y + h, z    );
  glEnd();

  // left
  glBegin(GL_QUADS);
  glVertex3f(x, y    , z    );
  glVertex3f(x, y + h, z    );
  glVertex3f(x, y + h, z + w);
  glVertex3f(x, y    , z + w);
  glEnd();

  // right
  glBegin(GL_QUADS);
  glVertex3f(x + l, y    , z    );
  glVertex3f(x + l, y + h, z    );
  glVertex3f(x + l, y + h, z + w);
  glVertex3f(x + l, y    , z + w);
  glEnd();
}
