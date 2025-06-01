#include <GL/glut.h>

#include "camera.hpp"
#include "structure.hpp"
#include "CameraInstance.h"

Camera& cam1 = globalCamera;

void update() {

}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  cam1.applyView();

  structure();

  glutSwapBuffers();
}

void reshape(const int width, int height) {
  if (height == 0) height = 1;
  const float aspect = static_cast<float>(width) / static_cast<float>(height);

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // fovy = 45 deg, zNear = 1.0, zFar = 500.0
  gluPerspective(45.0, aspect, 1.0, 500.0);
}
