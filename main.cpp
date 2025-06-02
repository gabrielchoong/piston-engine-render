#include <GL/glut.h>

#include "core/init.hpp"
#include "core/input.hpp"
#include "core/callbacks.hpp"

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Single Piston Cylinder");

  InitOpenGL();
  InitScene();

  glutDisplayFunc(display);
  glutIdleFunc(update);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);

  glutMainLoop();
  return 0;
}
