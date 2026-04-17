[README.md](https://github.com/user-attachments/files/26836393/README.md.md)
# C Ordenation System

> Implementation of classic sorting algorithms in C using abstract data types.

[![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))

## Overview

A collection of sorting algorithm implementations in C, built around abstract data type (ADT) structures. Focuses on correctness, modularity, and understanding of low-level memory management — including manual allocation and pointer arithmetic.

## Algorithms Implemented

| Algorithm | Average Case | Worst Case | Space |
|---|---|---|---|
| Bubble Sort | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n²) | O(log n) |

## Data Structures Used

- Linked lists (singly and doubly linked)
- Dynamic arrays
- Abstract data type wrappers (generic element handling via `void*`)

## Getting Started

```bash
git clone https://github.com/vfiedlerc/c-ordenation-system.git
cd c-ordenation-system

# Compile
gcc -o ordenation main.c -Wall

# Run
./ordenation
```

## Key Concepts

- **Abstract Data Types** — sorting routines operate on generic element types via function pointers for comparison
- **Manual memory management** — explicit `malloc` / `free` throughout
- **Pointer arithmetic** — direct memory traversal in linked structures

---

*Computer Science fundamentals project — Systems Analysis & Development, UniBF*
