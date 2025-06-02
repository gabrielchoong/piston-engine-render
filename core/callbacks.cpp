#include <GL/glut.h>

#include "Camera.hpp"
#include "../components/structure.hpp"
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
  glViewport(0, 0, width, height);
  cam1.updateProjection(static_cast<float>(width), height);
}
