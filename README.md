# C++ Module 06 - Scalar Conversion and Serialization

## Overview

This repository contains solutions for Module 06 of the 42 School's C++ curriculum. The focus of this module is on implementing scalar type conversion, serialization, and type identification using C++98, exploring casting, exception handling, and the use of polymorphism.

## Status

Validated on 2024/02/13.  
Grade: 100%.

## General Information

- **Compiler used:** `c++`
- **Compilation flags:** `-Wall -Wextra -Werror -std=c++98`
- **Standard:** C++98, following 42 School curriculum requirements.

## Projects

This module is divided into three exercises, each focused on unique aspects of C++ casting, serialization, and type identification.

### Exercise 00: Conversion of Scalar Types
- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `ScalarConverter.{h,hpp}`, `ScalarConverter.cpp`
- **Description:**  
  The `ScalarConverter` class provides a static method `convert` that accepts a string representing a C++ literal in common formats (e.g., `char`, `int`, `float`, and `double`). It converts the literal to each scalar type, outputting the result or an informative message when conversion is impossible. The class is non-instantiable, adhering to the requirement that it stores no internal state.
- **Key Concepts:** Type detection, static functions, exception handling, conversion.

### Exercise 01: Serialization
- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `Serializer.{h,hpp}`, `Serializer.cpp`, `Data.{h,hpp}`
- **Description:**  
  The `Serializer` class offers methods for converting a `Data` object pointer to a `uintptr_t` integer using `serialize` and back to a `Data` pointer using `deserialize`. The `Data` structure includes members to demonstrate serialization. This exercise tests conversion consistency by comparing the original pointer to the deserialized output.
- **Key Concepts:** Serialization, pointer manipulation, memory representation.

### Exercise 02: Identify Real Type
- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`, `Base.{h,hpp}`, `Base.cpp`, `A.{h,hpp}`, `B.{h,hpp}`, `C.{h,hpp}`
- **Description:**  
  An abstract `Base` class serves as a polymorphic base for classes `A`, `B`, and `C`. A random generator function `generate` instantiates one of the derived classes, returning it as a `Base` pointer. The `identify` functions determine the actual type of the object at runtime, either by pointer or reference, without using `std::typeinfo`.
- **Key Concepts:** Polymorphism, dynamic casting, type identification.

## Compilation and Usage

Each exercise includes a `Makefile` for easy compilation. You can compile and run each exercise with the following commands:



