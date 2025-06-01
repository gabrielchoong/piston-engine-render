#ifndef TYPES_H
#define TYPES_H


struct Vec3f {
  float x, y, z;
};

struct Dimensions3f {
  float height, length, width;
};

struct Color3f {
  float red, green, blue;
};

struct Rotate4f {
  float angle;
  Vec3f axis;
};

using Translate3f = Vec3f;
using Scale3f = Vec3f;
using Eye3f = Vec3f;
using Center3f = Vec3f;
using Up3f = Vec3f;


#endif
