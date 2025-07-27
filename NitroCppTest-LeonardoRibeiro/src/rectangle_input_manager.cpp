#include "rectangle_input_manager.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
inline constexpr uint8_t kRequiredRectangles{10U};

void RectangleInputManager::load_input(std::string_view filename) {
  std::ifstream inFile(filename.cbegin());
  if (!inFile) {
    std::cerr << "Failed to open file.\n";
    return;
  }

  json json_input;
  try {
    inFile >> json_input;
  } catch (json::parse_error &e) {
    std::cerr << "JSON parsing error: " << e.what() << "\n";
    return;
  }

  std::string_view rects{"rects"};
  std::string_view x{"x"}, y{"y"}, w{"w"}, h{"h"};

  if (!json_input.contains(rects) || !json_input[rects].is_array()) {
    std::cerr << "Invalid JSON format: 'rects' array missing.\n";
    return;
  }

  rectangles.reserve(kRequiredRectangles);
  for (const auto &item : json_input[rects]) {
    if (rectangles.size() >= kRequiredRectangles)
      break;
    if (!item.contains(x) || !item.contains(y) || !item.contains(w) ||
        !item.contains(h)) {
      std::cerr << "Invalid rectangle definition.\n";
      continue;
    }
    if (item[w] <= 0 || item[h] <= 0) {
      std::cerr << "This is not a rectangle, height of width invalid.\n";
      continue;
    }
    rectangles.push_back(Rectangle{item[x], item[y], item[w], item[h]});
  }
}

const std::vector<Rectangle> &RectangleInputManager::get_rectangles() const {
  return rectangles;
}

void RectangleInputManager::print_rectangles() const {
  std::cout << "Input rectangles:\n";
  for (const auto &rectangle : rectangles)
    rectangle.print();
}
