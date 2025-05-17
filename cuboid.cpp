#include <GL/glut.h>

#include "types.h"
#include "cuboid.hpp"

void Cuboid(const Dimensions3f& dimensions,
            const Color3f& color,
            const Translate3f& position,
            const Rotate4f& rotation,
            const Scale3f& scale) {
  glPushMatrix();

  glColor3f(color.red, color.green, color.blue);
  glTranslatef(position.x, position.y, position.z);
  glRotatef(rotation.angle, rotation.axis.x, rotation.axis.y, rotation.axis.z);
  glScalef(scale.x, scale.y, scale.z);

  drawCuboid(dimensions);

  glPopMatrix();
}

void drawCuboid(const Dimensions3f& dimensions) {
  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;

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
