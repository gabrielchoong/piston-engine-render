#include "Piston.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include "../shapes/Circle.hpp"
#include "../shapes/Cuboid.hpp"
#include "../shapes/Cylinder.hpp"

Piston::Piston(const Vec3f &basePosition,
               float pistonHeight,
               float pistonRadiusTop,
               float pistonRadiusBottom,
               float crankPinHeight,
               float crankPinRadiusTop,
               float crankPinRadiusBottom,
               float rodHeight,
               float rodLength,
               float rodWidth)
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
  glPushMatrix();
  // to position the piston at the starting position
  glTranslatef(basePosition.x, basePosition.y, basePosition.z);
  glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);

  drawPistonHead(pistonRadiusTop,
                 pistonRadiusBottom,
                 pistonHeight,
                 50,
                 100);
  glPopMatrix();

  glPushMatrix();
  // to ensure the rod appears at the correct position
  // under the piston head and doesn't intersect in weird ways
  glTranslatef(0, -pistonHeight - rodHeight, 0);
  glColor3f(0.0f, 0.0f, 1.0f);
  glTranslatef(-rodLength / 2.0f, 0, -rodWidth / 2.0f);

  drawConnectingRod(
    Dimensions3f{rodHeight, rodLength, rodWidth});
  glPopMatrix();

  glPushMatrix();
  // this is also to ensure the crank pin
  // renders under the connecting rod
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

void Piston::update(float crankAngle) {
}

void drawPistonHead(float pistonRadiusTop,
                    float pistonRadiusBottom,
                    float pistonHeight,
                    int slices,
                    int stacks) {
  GLUquadric *quad = gluNewQuadric();

  glPushMatrix();
  // to flip the circle on its side
  glRotatef(180.0f, 1.0f, 0.0f, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  Circle bottomCircle(quad,
                      pistonRadiusBottom,
                      slices);
  glPopMatrix();

  glColor3f(1.0f, 0.0f, 0.0f);
  Cylinder cylinder(quad,
                    pistonRadiusTop,
                    pistonRadiusBottom,
                    pistonHeight,
                    slices,
                    stacks);

  glPushMatrix();
  glTranslatef(0.0f, 0.0f, pistonHeight);
  Circle topCircle(quad,
                   pistonRadiusTop,
                   slices);
  glPopMatrix();

  bottomCircle.draw();
  cylinder.draw();
  topCircle.draw();

  gluDeleteQuadric(quad);
}

void drawConnectingRod(const Dimensions3f dimension) {
  const Cuboid connectingRod(dimension);

  connectingRod.draw();
}

void drawCrankPin(float radiusTop,
                  float radiusBottom,
                  float height,
                  int slices,
                  int stacks) {
  GLUquadric *quad = gluNewQuadric();

  Cylinder cylinder(quad,
                    radiusTop,
                    radiusBottom,
                    height,
                    slices,
                    stacks);

  cylinder.draw();

  gluDeleteQuadric(quad);
}
