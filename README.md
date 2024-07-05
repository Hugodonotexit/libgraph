## libgraph: A Simple C++ Library for Interactive Graphing

**libgraph** is a lightweight C++ library designed to simplify interactive graphing. It provides a user-friendly interface to define, evaluate, and visualize mathematical functions, as well as draw lines and points on a graphical canvas. Built upon SDL (Simple DirectMedia Layer), it offers a basic yet effective platform for visualization and exploration of mathematical concepts.

**Key Features:**

- **Function Parsing and Evaluation:** libgraph utilizes a `Func` class to parse and validate mathematical functions expressed as strings. It supports a range of operations, including arithmetic, trigonometric, and logarithmic functions. 
- **Interactive Graphing:** The `SDLG` class handles the graphical representation of functions and lines. It provides a customizable canvas with adjustable zoom and pan features, enabling users to explore the visualized data interactively.
- **Basic Drawing Primitives:** The library allows users to draw lines and points on the canvas, providing additional flexibility for visual representation.
- **Customizable Colors:** Both functions and drawing elements can be customized with different colors, improving clarity and visual appeal.

**Core Classes:**

- **`Func`:** Represents a mathematical function parsed from a string.
    - `setFunc(std::string func)`: Sets the function string.
    - `getFunc()`: Returns the function string.
    - `get_y(double x)`: Evaluates the function for a given `x` value.
- **`SDLG`:** Handles the graphical rendering and user interactions.
    - `setWinSize(int width, int height)`: Sets the window size.
    - `setWinwColour(Colour colour)`: Sets the background color.
    - `run()`: Starts the graphical loop, handling events and rendering.
    - `setLine(Vectorlf a, Vectorlf b, Colour colour)`: Draws a line segment.
    - `deleteLine(int index)`: Deletes a line segment.
    - `pushFunc(Func func, Colour colour)`: Adds a function to the graph.
    - `removeFunc(int i)`: Removes a function from the graph.

**Example Usage:**

```cpp
#include "sdlgaphic.hpp"
#include <iostream>

int main() {
  // Create an SDLG object with default settings
  sgt::SDLG graph;

  // Define a function
  sgt::Func function("sin(x) + cos(x)");

  // Add the function to the graph
  graph.pushFunc(function);

  // Set a line
  graph.setLine(sgt::Vectorlf(0, 0), sgt::Vectorlf(10, 10), sgt::Colour::Red());

  // Run the graphical loop
  graph.run();

  return 0;
}
```


**Core Dependencies:**

* **SDL (Simple DirectMedia Layer):** This is the primary dependency for graphical rendering. It provides the foundation for creating windows, managing events, and drawing graphics.
* **SDL_ttf:** This library is used for rendering text on the graph. It allows you to display labels, axes, and other text elements.

**Optional Dependencies:**

* **OpenMP:** This library can be used for parallel processing, potentially accelerating the evaluation of functions for large datasets. However, it's not strictly required for basic functionality.

**Note:** The dependencies need to be installed on your system before you can compile and run `libgraph`. The installation instructions for each dependency are provided in the "Installation" section of the documentation.

Here's a breakdown of why each dependency is needed:

* **SDL:** Provides the core functionality for creating a graphical window, handling user input (mouse and keyboard), and drawing lines, curves, and other graphical elements.
* **SDL_ttf:** Enables the rendering of text within the graph window. This is crucial for displaying labels, axes, and other textual information.
* **OpenMP:**  Allows for parallel execution of tasks, potentially improving performance for computationally intensive functions. However, it's not essential for the basic functionality of the library.

**Installation:**

1. **Install SDL:** Follow the instructions for your operating system: [https://www.libsdl.org/](https://www.libsdl.org/)
2. **Install SDL_ttf:** Follow the instructions for your operating system: [https://www.libsdl.org/projects/SDL_ttf/](https://www.libsdl.org/projects/SDL_ttf/)
3. **Include the `sdlgaphic.hpp` header file in your project.**

**License:**

MIT License

**Contributions:**

Contributions are welcome! Please fork the repository and submit a pull request.

**Contact:**

For questions or issues, please open an issue on the GitHub repository.
