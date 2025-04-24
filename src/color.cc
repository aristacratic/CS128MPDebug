#include "color.hpp"

Color::Color(int r, int g, int b): red_(r), green_(g), blue_(b) {
  // need to ensure valid color has been constructed...
  const int kColorMin = 0;
  const int kColorMax = 255;
  if (red_ < kColorMin || red_ > kColorMax)
    throw std::runtime_error("Invalid input");
  if (green_ < kColorMin || green_ > kColorMax)
    throw std::runtime_error("Invalid input");
  if (blue_ < kColorMin || blue_ > kColorMax)
    throw std::runtime_error("Invalid input");
}

// do not modify
bool operator==(const Color& rhs, const Color& lhs) {
  return (rhs.Red() == lhs.Red() && rhs.Green() == lhs.Green() &&
          rhs.Blue() == lhs.Blue());
}