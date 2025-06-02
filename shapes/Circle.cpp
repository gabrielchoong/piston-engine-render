#include "Circle.hpp"

Circle::Circle(GLUquadric* quad,
               float radius,
               int slices,
               Rotate4f rotation,
               Translate3f translation)
                 : quad(quad),
                   radius(radius),
                   slices(slices),
                   rotation(rotation),
                   translation(translation) {}

void Circle::draw() const {
  glPushMatrix();

  glRotatef(rotation.angle, rotation.axis.x, rotation.axis.y, rotation.axis.z);
  glTranslatef(translation.x, translation.y, translation.z);
  gluDisk(quad,
          0.0f,
          radius,
          slices,
          1);

  glPopMatrix();
}
