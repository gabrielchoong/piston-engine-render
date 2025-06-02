#include <GL/freeglut_std.h>

#include "../types.h"
#include "input.hpp"
#include "Camera.hpp"
#include "CameraInstance.h"

Camera& cam = globalCamera;

void keyboard(unsigned char key, int x, int y) {
  Eye3f newEye = cam.getEye();
  Center3f newCenter = cam.getCenter();
  Up3f newUp = cam.getUp();

  constexpr float delta = 0.3f;

  switch (key) {
    case 'w':
      newEye.y -= delta;
      break;
    case 's':
      newEye.y += delta;
      break;
    case 'a':
      newEye.x += delta;
      break;
    case 'd':
      newEye.x -= delta;
      break;
    case 'q':
      newEye.z -= delta;
      break;
    case 'e':
      newEye.z += delta;
      break;
    case 'r':
      newEye.x = 0.0f;
      newEye.y = 0.0f;
      newEye.z = 3.0f;
      break;
    case 27: // Escape Key
      exit(0);
    default: ;
  }

  cam.updateAll(newEye, newCenter, newUp);

  glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y) {

}