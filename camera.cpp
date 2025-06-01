#include <GL/glu.h>

#include "types.h"
#include "camera.hpp"

Camera::Camera() {
  eyeX = 0.0f; eyeY = 0.0f; eyeZ = 3.0f;
  centerX = 0.0f; centerY = 0.0f; centerZ = 0.0f;
  upX = 0.0f; upY = 1.0f; upZ = 0.0f;
}

void Camera::applyView() const {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyeX, eyeY, eyeZ,
            centerX, centerY, centerZ,
            upX, upY, upZ);
}

Eye3f Camera::getEye() const {
  return Eye3f{eyeX, eyeY, eyeZ};
}

void Camera::updateEye(const Eye3f& eye) {
  eyeX = eye.x;
  eyeY = eye.y;
  eyeZ = eye.z;
}

Center3f Camera::getCenter() const {
  return Center3f{centerX, centerY, centerZ};
}

void Camera::updateCenter(const Center3f& center) {
  centerX = center.x;
  centerY = center.y;
  centerZ = center.z;
}

Up3f Camera::getUp() const {
  return Up3f{upX, upY, upZ};
}

void Camera::updateUp(const Up3f &up) {
  upX = up.x;
  upY = up.y;
  upZ = up.z;
}

void Camera::updateAll(const Eye3f &eye, const Center3f &center, const Up3f &up) {
  updateEye(eye);
  updateCenter(center);
  updateUp(up);
}
