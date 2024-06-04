# Function Parser and Evaluator Library

## Overview

This library provides functionality to parse, validate, and evaluate mathematical functions represented as strings. It is designed to handle a variety of operations, including basic arithmetic and more complex functions like trigonometric and logarithmic operations.

## Features

- Parse and validate mathematical functions.
- Evaluate functions for given input values.
- Support for a wide range of operators and functions.
- Error handling for invalid functions.

## Installation

To use this library, simply include the header files in your project.

```cpp
#include "sdlgaphic.hpp"
```

## Usage

### Creating a Function Object

You can create a Func object by passing a mathematical function as a string:

```cpp
sgt::Func myFunction("sin(x) + cos(x) - 2*x");
```

### Creating a Function Object

You can set or update the function string using the setFunc method:

```cpp
myFunction.setFunc("x^2 + 3*x - 4");
```

### Getting the Function

You can retrieve the current function string using the getFunc method:

```cpp
std::string funcStr = myFunction.getFunc();
std::cout << "Current function: " << funcStr << std::endl;
```

### Evaluating the Function

To evaluate the function for a given x value:

```cpp
double y = myFunction.get_y(2.0);
std::cout << "f(2.0) = " << y << std::endl;
```

## Error Handling

The library includes error checking to ensure the validity of the function. If an invalid function is provided, a std::logic_error will be thrown with an appropriate error message.

## License

This library is licensed under the MIT License. See the LICENSE file for more details.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## Contact

For any questions or issues, please open an issue on the GitHub repository or contact the author.
