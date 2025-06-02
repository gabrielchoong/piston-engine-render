#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "../types.h"

class Camera {
public:
  float eyeX, eyeY, eyeZ;
  float centerX, centerY, centerZ;
  float upX, upY, upZ;

  Camera();

  void applyView() const;

  [[nodiscard]] Eye3f getEye() const;
  void updateEye(const Eye3f& eye);
  [[nodiscard]] Center3f getCenter() const;
  void updateCenter(const Center3f& center);
  [[nodiscard]] Up3f getUp() const;
  void updateUp(const Up3f& up);

  void updateAll(const Eye3f& eye, const Center3f& center, const Up3f& up);

  static void updateProjection(float width, float height);
};

#endif
