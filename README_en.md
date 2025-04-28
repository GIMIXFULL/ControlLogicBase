# ControlLogicBase

This project provides a basic framework for creating keyboard-controlled programs (especially games), with separated control logic and the main thread.

## Purpose

The main goal of this project is to simplify and accelerate the development of programs that require keyboard control. It provides a separation of responsibilities between:

•   **Command control flow:** Handles keyboard input and translates it into commands.
•   **Main thread:** Executes the main logic of the program (e.g., game logic, rendering).

This separation allows you to:

•   Avoid blocking the main thread while waiting for user input.
•   Improve code structure by separating control logic from application logic.
•   Simplify the addition of new commands and modification of existing controls.

## Structure

The project consists of the following main components:

•   **`program` class:**
    •   Contains the `comm_end` and `comm_start` flags for managing threads.
    •   `command_control_flow()` function: Runs in a separate thread and is responsible for handling keyboard input. Handles key presses and performs corresponding actions. In the current implementation, only the Escape key (program exit) is processed.
    •   `start()` function: Starts the control flow thread and then executes the main program loop.
    •   `setCommEndFalse()` function: Sets the `comm_end` flag to `false` to terminate the program.

## Usage

1.  **Include the header file:** `#include "your_file_name.h"` in your project.
2.  **Create an instance of the `program` class:** `program my_program;`
3.  **Start the program:** `my_program.start();`
4.  **Implement control logic:** In the `command_control_flow()` function, add handling for various keys. Use `else if` to add new commands.
5.  **Implement the main program logic:** Add code to the main loop (`while (comm_end)` in the `start()` function).

## Future plans

•   Add cross-platform support for keyboard input.
•   Provide a more flexible mechanism for registering and handling commands.
•   Create usage examples for various types of applications (games, console utilities, etc.).

## License

This project is distributed under the [MIT].

## Author

[GIMIXFULL]

---

# ControlLogicBase