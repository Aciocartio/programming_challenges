#include "intersection_detector.h"
#include "rectangle_input_manager.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Missing input file.\n\nUsage: " << argv[0] << " <file_name>\n";
    return 1;
  }

  RectangleInputManager input_manager{};
  input_manager.load_input(argv[1]);
  if (!input_manager.loading_successful()) {
    return 1;
  }
  input_manager.print_rectangles();

  IntersectionDetector detector(input_manager.get_rectangles());
  detector.compute_intersections();
  detector.print_intervals();

  return 0;
}
