#include "rectangle.h"
#include <iostream>

// Rectangle
Rectangle::Rectangle(int x, int y, int w, int h) : x{x}, y{y}, w{w}, h{h} {}

void Rectangle::print() const {
  std::cout << "Rectangle at (" << x << ", " << y << "), w=" << w << ", h=" << h
            << ".\n";
}

bool Rectangle::is_valid() const { return w > 0 && h > 0; }

bool Rectangle::operator==(const Rectangle &other) const {
  return x == other.x && y == other.y && w == other.w && h == other.h;
}
