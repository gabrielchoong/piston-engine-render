#ifndef PISTONHEAD_HPP
#define PISTONHEAD_HPP

class PistonHead {
public:
  PistonHead(float pistonRadiusTop,
             float pistonRadiusBottom,
             float pistonHeight,
             int slices,
             int stacks);

  void draw() const;

private:
  float pistonRadiusTop, pistonRadiusBottom, pistonHeight;
  int slice, stack;
};

#endif
