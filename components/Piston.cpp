#include "Piston.hpp"

#include <GL/gl.h>

#include "ConnectingRod.hpp"
#include "CrankPin.hpp"
#include "PistonHead.hpp"

// TODO: clean up constructor variables into vectors
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

  // TODO: dynamic slices and stacks value
  const PistonHead pistonHead(pistonRadiusTop,
                              pistonRadiusBottom,
                              pistonHeight,
                              50,
                              100);
  pistonHead.draw();
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

  const Dimensions3f rodDimensions = {rodHeight, rodLength, rodWidth};

  const ConnectingRod connectingRod(rodDimensions);
  connectingRod.draw();
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

  const CrankPin crankpin(crankPinRadiusTop,
                          crankPinRadiusBottom,
                          crankPinHeight,
                          50,
                          100);

  crankpin.draw();
  glPopMatrix();
}

// TODO: implement update method for animation
// void Piston::update(float crankAngle) {
// }
