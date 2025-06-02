#include "Piston.hpp"

#include <GL/gl.h>
#include <GL/glu.h>

#include "../shapes/Circle.hpp"
#include "../shapes/Cuboid.hpp"
#include "../shapes/Cylinder.hpp"

Piston::Piston(const Vec3f& basePosition,
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
    rodWidth(rodWidth)
{}

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
  glTranslatef(0, -pistonHeight-rodHeight, 0);
  glColor3f(0.0f, 0.0f, 1.0f);

  drawConnectingRod(
  Dimensions3f{rodHeight, rodLength, rodWidth},
  Translate3f{-0.15f, 0.0f, -0.15f},
  Rotate4f{0.0f, 0.0f, 0.0f, 0.0f},
  Scale3f{1.0f, 1.0f, 1.0f});
  glPopMatrix();

  glPushMatrix();
  // this is also to ensure the crank pin
  // renders under the connecting rod
  glTranslatef(0, -pistonHeight-rodHeight-crankPinHeight, 0);
  glColor3f(0.0f, 1.0f, 0.0f);

  glTranslatef(0.0f, 0, -0.05f);
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

  GLUquadric* quad = gluNewQuadric();

  Circle bottomCircle(quad,
                      pistonRadiusBottom,
                      slices,
                      Rotate4f{180.0f, 1.0f, 0.0f, 0.0f},
                      Translate3f{0.0f, 0.0f, 0.0f});

  Cylinder cylinder(quad,
                    pistonRadiusTop,
                    pistonRadiusBottom,
                    pistonHeight,
                    slices,
                    stacks);

  Circle topCircle(quad,
                   pistonRadiusTop,
                   slices,
                   Rotate4f{0.0f, 0.0f, 0.0f, 0.0f},
                   Translate3f{0.0f, 0.0f, pistonHeight});

  bottomCircle.draw();
  cylinder.draw();
  topCircle.draw();

  gluDeleteQuadric(quad);
}

void drawConnectingRod(Dimensions3f dimension,
                       Translate3f translate,
                       Rotate4f rotate,
                       Scale3f scale) {
  Cuboid connectingRod(
    dimension, translate, rotate, scale
    );

  connectingRod.draw();
}

void drawCrankPin(float radiusTop,
                  float radiusBottom,
                  float height,
                  int slices,
                  int stacks) {
  GLUquadric* quad = gluNewQuadric();

  Cylinder cylinder(quad,
                    radiusTop,
                    radiusBottom,
                    height,
                    slices,
                    stacks);

  cylinder.draw();

  gluDeleteQuadric(quad);
}
