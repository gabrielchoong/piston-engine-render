#include <GL/glut.h>

#include "ground.hpp"
#include "structure.hpp"

void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // display functions
  // ground();
  structure();

  glutSwapBuffers();
}

void reshape(int width, int height) {
  if (height == 0) height = 1;
  float aspect = (float) width / (float) height;

  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, aspect, 1.0, 5000.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Car Structural Frame");

  // glEnable(GL_DEPTH_TEST);

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
