#include <GL/glut.h>

void ground() {
  gluLookAt(0.0, 200.0, 500.0,
      0.0, 0.0, 0.0,
      0.0, 1.0, 0.0);

  glBegin(GL_LINES);
  for (int i = -1000; i <= 1000; i += 25) {
    glColor3f(i == 0 ? 0.0f : 0.5f, 0.5f, 0.5f);

    // Vertical lines (Z direction)
    glVertex3f(i, 0, -1000);
    glVertex3f(i, 0, 1000);

    // Horizontal lines (X direction)
    glVertex3f(-1000, 0, i);
    glVertex3f(1000, 0, i);
  }
  glEnd();
}
