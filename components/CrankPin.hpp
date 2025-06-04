#ifndef CRANKPIN_HPP
#define CRANKPIN_HPP

class CrankPin {
public:
  CrankPin(float crankPinTopRadius,
           float crankPinBottomRadius,
           float crankPinHeight,
           int slice,
           int stack);

  void draw() const;

private:
  float crankPinTopRadius, crankPinBottomRadius, crankPinHeight;
  int slice, stack;
};

#endif //CRANKPIN_HPP
