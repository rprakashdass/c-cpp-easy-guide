# C++ STL: Set

This markdown file provides a concise summary of the **std::set**, **std::unordered_set**, and **std::multiset** containers, with comparisons, essential methods, and examples to help you understand their differences and usage.

---

## Table of Contents
1. [What is a Set?](#what-is-a-set)
2. [Types of Sets](#types-of-sets)
   - [std::set](#stdset)
   - [std::unordered_set](#stdunordered_set)
   - [std::multiset](#stdmultiset)
3. [Comparing Set Types](#comparing-set-types)
4. [Commonly Used Methods](#commonly-used-methods)
   - [Initialization](#1-initialization)
   - [Adding Elements](#2-adding-elements)
   - [Removing Elements](#3-removing-elements)
   - [Accessing and Iteration](#4-accessing-and-iteration)
5. [Algorithm Analysis](#algorithm-analysis)
6. [Example: Sorting Elements](#example-sorting-elements)
7. [Notes](#notes)

---

## What is a Set?
A `set` is an associative container in C++ that stores unique elements in sorted or unsorted order, depending on the type of set. It ensures there are no duplicate elements and provides efficient operations for insertion, deletion, and search.

---

## Types of Sets

### `std::set`
- Stores **unique elements** in **sorted order**.
- Backed by a **balanced binary search tree** (usually a Red-Black Tree).
- Provides **logarithmic time complexity** for insertion, deletion, and search.

```cpp
#include <set>
std::set<int> s = {3, 1, 4, 1, 5}; // Duplicate '1' will be ignored
// s = {1, 3, 4, 5}
```

### `std::unordered_set`
- Stores **unique elements** in **no particular order**.
- Backed by a **hash table**.
- Provides **average constant time complexity** for insertion, deletion, and search.
  - May degrade to **O(n)** in the worst case (e.g., hash collisions).

```cpp
#include <unordered_set>
std::unordered_set<int> us = {3, 1, 4, 1, 5}; // Duplicate '1' will be ignored
// Possible order: {3, 1, 4, 5} (not guaranteed)
```

### `std::multiset`
- Stores **duplicate elements** in **sorted order**.
- Backed by a **balanced binary search tree** (like `std::set`).
- Provides **logarithmic time complexity** for insertion, deletion, and search.

```cpp
#include <set>
std::multiset<int> ms = {3, 1, 4, 1, 5}; // Allows duplicate '1'
// ms = {1, 1, 3, 4, 5}
```

---

## Comparing Set Types

| Feature                | `std::set`      | `std::unordered_set` | `std::multiset` |
|------------------------|-----------------|----------------------|-----------------|
| **Ordering**           | Sorted          | Unordered            | Sorted          |
| **Duplicates Allowed** | No              | No                   | Yes             |
| **Underlying Structure** | Balanced BST  | Hash Table           | Balanced BST    |
| **Insertion Complexity** | O(log n)       | O(1) avg, O(n) worst | O(log n)       |
| **Search Complexity**   | O(log n)       | O(1) avg, O(n) worst | O(log n)       |
| **Use Case**           | Ordered unique elements | Fast unique lookups | Ordered duplicates |

---

## Commonly Used Methods

### 1. Initialization
```cpp
#include <set>
#include <unordered_set>

std::set<int> s = {1, 2, 3};           // Ordered unique elements
std::unordered_set<int> us = {3, 2, 1}; // Unordered unique elements
std::multiset<int> ms = {1, 2, 2, 3};   // Ordered with duplicates
```

### 2. Adding Elements
```cpp
s.insert(4);       // Inserts 4 into std::set
us.insert(5);      // Inserts 5 into std::unordered_set
ms.insert(6);      // Inserts 6 into std::multiset
```

### 3. Removing Elements
```cpp
s.erase(2);        // Removes element 2 from std::set
us.erase(3);       // Removes element 3 from std::unordered_set
ms.erase(2);       // Removes all occurrences of 2 from std::multiset

// To remove only one occurrence in multiset:
ms.erase(ms.find(2));
```

### 4. Accessing and Iteration
```cpp
// Iterating through std::set
for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << " ";
}

// Iterating through std::unordered_set
for (int x : us) {
    std::cout << x << " ";
}

// Iterating through std::multiset
for (int x : ms) {
    std::cout << x << " ";
}
```

---

## Algorithm Analysis

### 1. `insert`
| Container           | Time Complexity |
|---------------------|-----------------|
| `std::set`          | O(log n)       |
| `std::unordered_set`| O(1) avg, O(n) worst |
| `std::multiset`     | O(log n)       |

### 2. `erase`
| Container           | Time Complexity |
|---------------------|-----------------|
| `std::set`          | O(log n)       |
| `std::unordered_set`| O(1) avg, O(n) worst |
| `std::multiset`     | O(log n)       |

### 3. `find`
| Container           | Time Complexity |
|---------------------|-----------------|
| `std::set`          | O(log n)       |
| `std::unordered_set`| O(1) avg, O(n) worst |
| `std::multiset`     | O(log n)       |

---

## Example: Sorting Elements

```cpp
#include <set>
#include <iostream>

int main() {
    std::multiset<int> ms = {5, 3, 1, 2, 4, 1};

    for (int x : ms) {
        std::cout << x << " ";
    }

    return 0;
}
```

**Output:**
```
1 1 2 3 4 5
```

---

## Notes:
1. Use `std::set` when you need sorted unique elements.
2. Use `std::unordered_set` for faster lookups when ordering is not required.
3. Use `std::multiset` when you need to store duplicates in sorted order.
4. Be mindful of hash collisions in `std::unordered_set`, which can degrade performance.
