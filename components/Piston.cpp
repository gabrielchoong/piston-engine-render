#include "Piston.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include "../shapes/Circle.hpp"
#include "../shapes/Cuboid.hpp"
#include "../shapes/Cylinder.hpp"

Piston::Piston(const Vec3f &basePosition,
               const float pistonHeight,
               const float pistonRadiusTop,
               const float pistonRadiusBottom,
               const float crankPinHeight,
               const float crankPinRadiusTop,
               const float crankPinRadiusBottom,
               const float rodHeight,
               const float rodLength,
               const float rodWidth)
  : basePosition(basePosition),
    pistonHeight(pistonHeight),
    pistonRadiusTop(pistonRadiusTop),
    pistonRadiusBottom(pistonRadiusBottom),
    crankPinHeight(crankPinHeight),
    crankPinRadiusTop(crankPinRadiusTop),
    crankPinRadiusBottom(crankPinRadiusBottom),
    rodHeight(rodHeight),
    rodLength(rodLength),
    rodWidth(rodWidth) {
}

void Piston::draw() const {

  /*
   * Rendering the head of the piston
   */
  glPushMatrix();
  /* to position the piston at the starting position */
  glTranslatef(basePosition.x, basePosition.y, basePosition.z);
  glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);

  drawPistonHead(pistonRadiusTop,
                 pistonRadiusBottom,
                 pistonHeight,
                 50,
                 100);
  glPopMatrix();


  /*
   * Rendering the connecting rod of the piston
   */
  glPushMatrix();
  /* to ensure the rod appears at the correct position
  under the piston head and doesn't intersect in weird ways */
  glTranslatef(0, -pistonHeight - rodHeight, 0);
  glColor3f(0.0f, 0.0f, 1.0f);
  glTranslatef(-rodLength / 2.0f, 0, -rodWidth / 2.0f);

  Dimensions3f rodDimensions = {rodHeight, rodLength, rodWidth};

  drawConnectingRod(rodDimensions);
  glPopMatrix();


  /*
   * Rendering the crank pin of the piston
   */
  glPushMatrix();
  /* this is also to ensure the crank pin
  renders under the connecting rod */
  glTranslatef(0, -pistonHeight - rodHeight - crankPinHeight, 0);
  glColor3f(0.0f, 1.0f, 0.0f);

  glTranslatef(0.0f, 0, -crankPinHeight / 2.0f);
  drawCrankPin(crankPinRadiusTop,
               crankPinRadiusBottom,
               crankPinHeight,
               50,
               100);
  glPopMatrix();
}

// void Piston::update(float crankAngle) {
// }

void drawPistonHead(const float pistonRadiusTop,
                    const float pistonRadiusBottom,
                    const float pistonHeight,
                    const int slices,
                    const int stacks) {
  GLUquadric *quad = gluNewQuadric();


  glPushMatrix();
  /* to flip the circle on its side */
  glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
  const Circle bottomCircle(quad,
                            pistonRadiusBottom,
                            slices);
  glPopMatrix();


  /* add gl-matrix if applying transformations */
  const Cylinder cylinder(quad,
                          pistonRadiusTop,
                          pistonRadiusBottom,
                          pistonHeight,
                          slices,
                          stacks);


  glPushMatrix();
  /* ensures a closed cylinder with top cap */
  glTranslatef(0.0f, 0.0f, pistonHeight);
  glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
  const Circle topCircle(quad,
                         pistonRadiusTop,
                         slices);
  glPopMatrix();


  bottomCircle.draw();
  cylinder.draw();
  topCircle.draw();

  gluDeleteQuadric(quad);
}

void drawConnectingRod(const Dimensions3f& dimension) {
  const Cuboid connectingRod(dimension);

  connectingRod.draw();
}

void drawCrankPin(const float radiusTop,
                  const float radiusBottom,
                  const float height,
                  const int slices,
                  const int stacks) {
  GLUquadric *quad = gluNewQuadric();

  const Cylinder cylinder(quad,
                          radiusTop,
                          radiusBottom,
                          height,
                          slices,
                          stacks);

  cylinder.draw();

  gluDeleteQuadric(quad);
}
