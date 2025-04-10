# 📐 Vector & Sparse Vector – OOP in C++

A university project exploring object-oriented programming through the implementation of **template-based vector classes** in C++. This project includes both a classic `Vektor` class and a memory-efficient `RitkaVektor` (Sparse Vector) class, showcasing operator overloading, type conversions, and exception handling.

## 🔧 Project Overview

The goal was to implement a templated `Vektor<T>` class and a sparse variant `RitkaVektor<T>` that only stores non-zero values along with their indices. The project demonstrates:

- Dynamic memory management
- Template classes and specialization
- Operator overloading (`+`, `-`, `*`, `%`, `~`, `[]`)
- Explicit type conversion between dense and sparse vectors
- Euclidean norm and distance calculation
- Exception handling for invalid operations

## 🚀 Features

- ➕ Vector addition and subtraction
- ✖️ Scalar product of two vectors
- 🌌 Euclidean norm `~` and distance `%`
- 🎯 Random-access read-only operator `[]`
- 🔁 Type conversion: `Vektor ↔ RitkaVektor`
- ⚠️ Error handling for invalid dimensions or indices

## 📁 File Structure

| File          | Description                                               |
|---------------|-----------------------------------------------------------|
| `vektor.h`    | Implementation of the `Vektor<T>` class (dense vector)    |
| `ritkavektor.h`| Implementation of the `RitkaVektor<T>` class (sparse)    |
| `Source.cpp`  | Main file for demonstrating functionality and testing     |

## 🛠️ Technologies Used

- **C++ Templates** – For type-generic implementation
- **OOP Principles** – Encapsulation, overloading, conversion operators
- **Standard Template Library (STL)** – Used `vector` in sparse vector class
- **Exception Handling** – Uses `try/catch` and `throw` for index/dimension checks
