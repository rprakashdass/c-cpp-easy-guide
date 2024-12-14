# C++ STL: Vector Methods

This markdown provides an in-depth overview of commonly used methods for `std::vector`, including their algorithms, complexities, and practical use cases. It serves as a concise reference for interview preparation.

## Introduction to Maps and Their Types

In the C++ Standard Template Library (STL), a `map` is an associative container that stores key-value pairs in sorted order. Maps provide efficient data retrieval based on keys, making them highly useful for tasks requiring fast lookups, insertions, or deletions based on unique keys.

### Characteristics of Maps:
- Keys are unique, and each key is associated with only one value.
- Internally implemented as a balanced binary search tree (usually a Red-Black Tree).
- Automatically sorts elements based on keys in ascending order by default.
- Offers logarithmic time complexity (O(log n)) for insertion, deletion, and lookup operations.

### Types of Maps:
1. **`std::map`**:
   - Stores elements in ascending order based on keys.
   - Does not allow duplicate keys.

2. **`std::multimap`**:
   - Allows multiple elements with the same key.
   - Stores elements in ascending order based on keys.

3. **`std::unordered_map`**:
   - Stores elements in an arbitrary order.
   - Provides average constant time complexity (O(1)) for insertion, deletion, and lookup.

4. **`std::unordered_multimap`**:
   - Allows multiple elements with the same key.
   - Stores elements in arbitrary order.

---

## Common Methods in Vectors

### 1. `push_back`
Appends an element to the end of the vector.

#### Syntax:
```cpp
vec.push_back(val);
```
#### Algorithm:
- Dynamically resizes the array if the capacity is exceeded.

#### Complexity:
| Operation           | Time Complexity            |
|---------------------|----------------------------|
| Regular Append      | O(1) amortized            |
| Resize Operation    | O(n)                      |

---

### 2. `pop_back`
Removes the last element from the vector.

#### Syntax:
```cpp
vec.pop_back();
```
#### Algorithm:
- Does not reduce the capacity of the vector.

#### Complexity:
| Operation           | Time Complexity            |
|---------------------|----------------------------|
| Remove Last Element | O(1)                      |

---

### 3. `insert`
Inserts elements at a specified position.

#### Syntax:
```cpp
vec.insert(iterator, val);
vec.insert(iterator, count, val);
vec.insert(iterator, range_begin, range_end);
```
#### Algorithm:
- Shifts subsequent elements to the right.

#### Complexity:
| Operation           | Time Complexity            |
|---------------------|----------------------------|
| Single Element      | O(n)                      |
| Multiple Elements   | O(n + m) (m: new elements)|

---

### 4. `erase`
Removes elements by iterator or range.

#### Syntax:
```cpp
vec.erase(iterator);
vec.erase(range_begin, range_end);
```
#### Algorithm:
- Shifts subsequent elements to the left.

#### Complexity:
| Operation           | Time Complexity            |
|---------------------|----------------------------|
| Single Element      | O(n)                      |
| Range Erase         | O(n)                      |

---

### 5. `resize`
Resizes the vector to the specified size.

#### Syntax:
```cpp
vec.resize(new_size);
vec.resize(new_size, val);
```
#### Algorithm:
- Adjusts the size, filling with default or specified values if the size is increased.

#### Complexity:
| Operation           | Time Complexity            |
|---------------------|----------------------------|
| Increase Size       | O(n - current size)        |
| Decrease Size       | O(1)                      |

---

### 6. `size` and `capacity`
- **`size`**: Returns the number of elements in the vector.
- **`capacity`**: Returns the number of elements the vector can store before reallocating.

#### Syntax:
```cpp
size_t sz = vec.size();
size_t cap = vec.capacity();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| `size` / `capacity` | O(1)           |

---

### 7. `clear`
Removes all elements from the vector.

#### Syntax:
```cpp
vec.clear();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Clear All Elements  | O(n)           |

---

### 8. `front` and `back`
- **`front`**: Returns a reference to the first element.
- **`back`**: Returns a reference to the last element.

#### Syntax:
```cpp
auto &first = vec.front();
auto &last = vec.back();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Access Front/Back   | O(1)           |

---

### 9. `emplace_back`
Constructs an element in place at the end of the vector.

#### Syntax:
```cpp
vec.emplace_back(args...);
```
#### Algorithm:
- More efficient than `push_back` as it avoids an unnecessary copy or move operation.

#### Complexity:
Same as `push_back`.

---

### 10. `at`
Accesses the element at the specified index with bounds checking.

#### Syntax:
```cpp
vec.at(index);
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Access by Index     | O(1)           |

---

### 11. Iterators
- **`begin`**: Returns iterator to the first element.
- **`end`**: Returns iterator past the last element.
- **`rbegin`**, **`rend`**: Reverse iterators.

#### Syntax:
```cpp
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Iterator Access     | O(1) per step  |

---

### 12. `swap`
Exchanges the contents of two vectors.

#### Syntax:
```cpp
vec1.swap(vec2);
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Swap Contents       | O(1)           |

---

## Summary Table of Methods

| Method              | Description                           | Complexity                     |
|---------------------|---------------------------------------|--------------------------------|
| `push_back`         | Append an element                    | O(1) amortized                |
| `pop_back`          | Remove the last element              | O(1)                          |
| `insert`            | Insert elements at a position        | O(n)                          |
| `erase`             | Remove element(s)                   | O(n)                          |
| `resize`            | Resize the vector                   | O(n - current size) / O(1)    |
| `size` / `capacity` | Size and capacity                   | O(1)                          |
| `clear`             | Clear all elements                  | O(n)                          |
| `front` / `back`    | Access first/last element            | O(1)                          |
| `emplace_back`      | In-place append                     | O(1) amortized                |
| `at`                | Access element with bounds checking | O(1)                          |
| Iterators           | Access elements using iterators      | O(1) per step                 |
| `swap`              | Swap contents with another vector    | O(1)                          |

---
