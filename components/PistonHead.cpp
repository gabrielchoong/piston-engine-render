#include "PistonHead.hpp"

#include <GL/gl.h>

#include "../shapes/Circle.hpp"
#include "../shapes/Cylinder.hpp"

PistonHead::PistonHead(float pistonRadiusTop,
                       float pistonRadiusBottom,
                       float pistonHeight,
                       int slice,
                       int stack)
  : pistonRadiusTop(pistonRadiusTop),
    pistonRadiusBottom(pistonRadiusBottom),
    pistonHeight(pistonHeight),
    slice(slice),
    stack(stack) {
}

void PistonHead::draw() const {
  GLUquadric *quad = gluNewQuadric();


  glPushMatrix();
  /* to flip the circle on its side */
  glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
  const Circle bottomCircle(quad,
                            pistonRadiusBottom,
                            slice);
  glPopMatrix();


  /* add gl-matrix if applying transformations */
  const Cylinder cylinder(quad,
                          pistonRadiusTop,
                          pistonRadiusBottom,
                          pistonHeight,
                          slice,
                          stack);


  glPushMatrix();
  /* ensures a closed cylinder with top cap */
  glTranslatef(0.0f, 0.0f, pistonHeight);
  glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
  const Circle topCircle(quad,
                         pistonRadiusTop,
                         slice);
  glPopMatrix();


  bottomCircle.draw();
  cylinder.draw();
  topCircle.draw();

  gluDeleteQuadric(quad);
}

