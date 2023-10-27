# Interview Task

This repository contains WIP project for candidates for Graphics Software Engineer Intern at Intel in Gdańsk.
Your task as candidate is to finish functionality and prepare some example data for tests.

## Task 1

Project has some structures defined in file `task\include\data.hpp` as well as interface for serialization of those structures to file in `task\include\serialization.hpp`.
Your first task is to implement that interface in file `task\source\serialization.cpp`.

### Requirements

- data should be stored in binary format
- if possible, you should avoid storing same data twice
- (de)serialization should be ready for future changes in data structures (also should be backward compatible)

## Task 2

This actually is rather subtask for [Task 1](#task-1) as you need to verify your code somehow.
In `task\source\main.cpp` prepare some example data, serialize and deserialize them and then verify results using interface from `task\include\verifier.hpp`.

### Requirements

- prepare different examples for different scenarios


## How to build

Project is configured that it works with MSVC on Windows and GCC on Linux using CMake for project configuration.
Repository also contains `CMakePresets.json` file that make CMake configuration easier and most convenient way to configure project is to use VSCode with proper configuration of CMake tools - [here](https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/cmake-presets.md) you can find details.

Project also has configuration for VSCode `devcontainer` with Docker container configured for Ubuntu.
You can use it to build Linux configuration if you prefer.
Instruction how to do it can be found [here](https://code.visualstudio.com/docs/devcontainers/containers).
