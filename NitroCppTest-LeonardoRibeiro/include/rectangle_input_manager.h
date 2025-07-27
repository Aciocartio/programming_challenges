#pragma once

#include "rectangle.h"
#include <string_view>
#include <vector>

class RectangleInputManager {
public:
  const std::vector<Rectangle> &get_rectangles() const;
  void load_input(std::string_view filename);
  bool loading_successful() const { return rectangles.size() > 0; };
  void print_rectangles() const;

private:
  std::vector<Rectangle> rectangles{};
};
