# Rectangle Intersection Detector

This C++ console application loads a set of rectangles from a JSON file and detects all 2D intersections — including overlaps involving 2 or more rectangles.

---

## Requirements

- CMake ≥ 3.15
- C++17-compatible compiler
- [nlohmann/json](https://github.com/nlohmann/json) (automatically fetched)
- [GoogleTest](https://github.com/google/googletest) (automatically fetched)

---

## Building the Project

The project uses **CMake** for cross-platform builds. Clone the repository and run:

### Linux / macOS

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

### Windows

```
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release
```

Replace the generator name with your installed Visual Studio version if needed.

## Running the Program

After building, execute the main binary with the path to a JSON file:

```
./rectangle_intersections path/to/input.json
```

Example JSON:

```json
{
  "rects": [
    { "x": 0, "y": 0, "w": 100, "h": 100 },
    { "x": 50, "y": 50, "w": 100, "h": 100 },
    { "x": 200, "y": 200, "w": 50, "h": 50 }
  ]
}
```

## Running Tests

The project includes unit tests using GoogleTest.

From the build directory:

```
ctest
```

Or run individual test binaries:

```
./test/intersection_detector_test
./test/rectangle_input_manager_test
./test/rectangle_test
```

Verbose output:

```
ctest --verbose
```
