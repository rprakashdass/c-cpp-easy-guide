# C++ STL: Vector

This markdown file provides a concise summary of the **std::vector** container, with essential concepts and syntax to help you review quickly before interviews.

---

## Table of Contents
1. [What is a Vector?](#what-is-a-vector)
2. [Advantages of Vector](#advantages-of-vector)
3. [Commonly Used Methods](#commonly-used-methods)
   - [Initialization](#1-initialization)
   - [Adding Elements](#2-adding-elements)
      - [push_back vs emplace_back](#push_back-vs-emplace_back)
   - [Removing Elements](#3-removing-elements)
   - [Accessing Elements](#4-accessing-elements)
   - [Iteration](#5-iteration)
   - [Capacity Functions](#6-capacity-functions)
   - [Other Useful Methods](#7-other-useful-methods)
4. [Algorithm Analysis for Key Methods](#algorithm-analysis-for-key-methods)
5. [Example: Sorting a Vector](#example-sorting-a-vector)
6. [Notes](#notes)

---

## What is a Vector?
A `vector` is a dynamic array in C++ that can resize itself automatically when elements are inserted or deleted. It stores elements in contiguous memory locations.

## Advantages of Vector:
- Dynamic resizing.
- Random access using indices (O(1)).
- Rich set of functions for insertion, deletion, and manipulation.

---

## Commonly Used Methods

### 1. Initialization
```cpp
#include <vector>

std::vector<int> vec1;            // Empty vector
std::vector<int> vec2(5);         // Vector of size 5 with default values (0 for int)
std::vector<int> vec3(5, 10);     // Vector of size 5, all initialized to 10
std::vector<int> vec4 = {1, 2, 3}; // Vector initialized with list
```

### 2. Adding Elements
```cpp
vec1.push_back(10); // Adds 10 at the end
vec1.emplace_back(20); // More efficient than push_back
```

#### `push_back` vs `emplace_back`
- **`push_back`**: Appends an existing object to the vector. Requires the object to be constructed beforehand, which can involve an extra copy or move operation.
- **`emplace_back`**: Constructs the object in place directly within the vector. This avoids unnecessary copies or moves, making it faster in scenarios where the object is constructed from arguments.

**Example:**
```cpp
#include <vector>
#include <iostream>
#include <utility> // for std::pair

int main() {
    std::vector<std::pair<int, int>> vec;

    vec.push_back(std::make_pair(1, 2)); // Constructs a pair, then copies it into the vector
    vec.emplace_back(3, 4);              // Constructs the pair directly in the vector

    for (const auto &p : vec) {
        std::cout << p.first << ", " << p.second << "\n";
    }
    return 0;
}
```

**Output:**
```
1, 2
3, 4
```

#### Time Complexity
- `push_back`: O(1) on average, but may involve O(n) if resizing occurs.
- `emplace_back`: Same complexity as `push_back`, but avoids the overhead of extra copies or moves.

### 3. Removing Elements
```cpp
vec1.pop_back(); // Removes the last element
vec1.clear();    // Removes all elements
```

### 4. Accessing Elements
```cpp
int first = vec1.front(); // First element
int last = vec1.back();   // Last element
int atIndex = vec1[2];    // Element at index 2
```

### 5. Iteration
```cpp
// Using iterator
for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it) {
    std::cout << *it << " ";
}

// Using range-based loop
for (int x : vec1) {
    std::cout << x << " ";
}
```

### 6. Capacity Functions
```cpp
vec1.size();     // Number of elements
vec1.capacity(); // Allocated storage size
vec1.resize(10); // Change size to 10
vec1.shrink_to_fit(); // Reduces capacity to match size
```

### 7. Other Useful Methods
```cpp
vec1.insert(vec1.begin() + 1, 99); // Insert 99 at index 1
vec1.erase(vec1.begin() + 2);     // Erase element at index 2
vec1.swap(vec2);                  // Swap contents with vec2
std::sort(vec1.begin(), vec1.end()); // Sort elements
```

---

## Algorithm Analysis for Key Methods

### 1. `push_back`
- **Time Complexity**: O(1) amortized. However, if resizing occurs (capacity exceeded), the complexity is O(n) due to copying all elements to a new memory location.
- **Space Complexity**: O(n) due to dynamic memory allocation for the new capacity.

### 2. `emplace_back`
- **Time Complexity**: O(1) amortized, with the same resizing caveat as `push_back`.
- **Space Complexity**: Same as `push_back`, but avoids the overhead of temporary object storage.

### 3. `erase`
- **Time Complexity**: O(n), as elements after the erased position need to be shifted.
- **Space Complexity**: O(1).

### 4. `insert`
- **Time Complexity**: O(n), as elements may need to be shifted to accommodate the new element.
- **Space Complexity**: O(1).

---

## Example: Sorting a Vector
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 1, 4, 2, 3};
    std::sort(vec.begin(), vec.end());

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```
**Output:**
```
1 2 3 4 5
```

---

## Notes:
1. Always prefer `emplace_back` over `push_back` for performance when constructing elements directly.
2. Be mindful of iterator invalidation during insertion and deletion.
