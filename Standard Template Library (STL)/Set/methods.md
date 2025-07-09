# C++ STL: Set Methods

This markdown provides an in-depth overview of the commonly used methods for `std::set`, `std::unordered_set`, and `std::multiset`, including their algorithms, complexities, and practical use cases. It serves as a concise reference for interview preparation.

---

# Table of Contents
  - [Common Methods in Sets](#Common-Methods-in-Sets)
  - [Summary Table of Methods](#summary-table-of-methods)

## Common Methods in Sets

### 1. `insert`
Inserts an element into the container.

#### Syntax:
```cpp
set.insert(val);
```
#### Algorithm:
- **std::set** and **std::multiset**: Inserts element using a balanced binary search tree.
- **std::unordered_set**: Inserts element into a hash table bucket.

#### Complexity:
| Container           | Time Complexity            |
|---------------------|----------------------------|
| `std::set`          | O(log n)                  |
| `std::unordered_set`| O(1) avg, O(n) worst      |
| `std::multiset`     | O(log n)                  |

---

### 2. `erase`
Removes elements by value or iterator.

#### Syntax:
```cpp
set.erase(val);
set.erase(iterator);
```
#### Algorithm:
- Removes element by adjusting tree nodes or hash buckets.

#### Complexity:
| Container           | Time Complexity            |
|---------------------|----------------------------|
| `std::set`          | O(log n)                  |
| `std::unordered_set`| O(1) avg, O(n) worst      |
| `std::multiset`     | O(log n) for one instance |

#### Example:
```cpp
std::multiset<int> ms = {1, 1, 2, 3};
ms.erase(1);  // Removes all occurrences of 1.
ms.erase(ms.find(2));  // Removes one occurrence of 2.
```

---

### 3. `find`
Searches for an element.

#### Syntax:
```cpp
auto it = set.find(val);
```
#### Algorithm:
- **std::set** and **std::multiset**: Binary search on tree nodes.
- **std::unordered_set**: Hash lookup.

#### Complexity:
| Container           | Time Complexity            |
|---------------------|----------------------------|
| `std::set`          | O(log n)                  |
| `std::unordered_set`| O(1) avg, O(n) worst      |
| `std::multiset`     | O(log n)                  |

---

### 4. `count`
Counts the number of occurrences of a value.

#### Syntax:
```cpp
size_t cnt = set.count(val);
```
#### Algorithm:
- **std::set**: Returns 1 if the value exists, otherwise 0.
- **std::multiset**: Returns the number of occurrences.

#### Complexity:
| Container           | Time Complexity            |
|---------------------|----------------------------|
| `std::set`          | O(log n)                  |
| `std::unordered_set`| O(1) avg, O(n) worst      |
| `std::multiset`     | O(log n)                  |

---

### 5. `lower_bound` and `upper_bound`
- **`lower_bound`**: Returns iterator to the first element >= key.
- **`upper_bound`**: Returns iterator to the first element > key.

#### Syntax:
```cpp
auto it = set.lower_bound(val);
auto it = set.upper_bound(val);
```
#### Complexity:
| Container           | Time Complexity |
|---------------------|-----------------|
| `std::set`          | O(log n)       |
| `std::multiset`     | O(log n)       |

**Note:** Not available for `std::unordered_set`.

---

### 6. `emplace`
Inserts a new element in place.

#### Syntax:
```cpp
set.emplace(val);
```
#### Complexity:
Same as `insert`.

---

### 7. `size` and `empty`
- **`size`**: Returns the number of elements in the container.
- **`empty`**: Checks if the container is empty.

#### Syntax:
```cpp
size_t sz = set.size();
bool isEmpty = set.empty();
```
#### Complexity:
| Container           | Time Complexity |
|---------------------|-----------------|
| All Sets            | O(1)           |

---

### 8. `clear`
Removes all elements from the container.

#### Syntax:
```cpp
set.clear();
```
#### Complexity:
| Container           | Time Complexity |
|---------------------|-----------------|
| All Sets            | O(n)           |

---

### 9. `swap`
Exchanges the contents of two sets.

#### Syntax:
```cpp
set1.swap(set2);
```
#### Complexity:
| Container           | Time Complexity |
|---------------------|-----------------|
| All Sets            | O(1)           |

---

### 10. Iterators
- **`begin`**: Returns iterator to the first element.
- **`end`**: Returns iterator past the last element.
- **`rbegin`**, **`rend`**: Reverse iterators.

#### Syntax:
```cpp
for (auto it = set.begin(); it != set.end(); ++it) {
    std::cout << *it << " ";
}
```
#### Complexity:
| Container           | Time Complexity |
|---------------------|-----------------|
| All Sets            | O(1) per step  |

---

## Summary Table of Methods

| Method              | Description                           | Complexity                     |
|---------------------|---------------------------------------|--------------------------------|
| `insert`            | Insert an element                    | O(log n) / O(1) avg (unordered) |
| `erase`             | Remove element(s)                    | O(log n) / O(1) avg (unordered) |
| `find`              | Search for an element                | O(log n) / O(1) avg (unordered) |
| `count`             | Count occurrences of an element      | O(log n) / O(1) avg (unordered) |
| `lower_bound`       | First element >= key                 | O(log n)                       |
| `upper_bound`       | First element > key                  | O(log n)                       |
| `emplace`           | In-place insertion                   | O(log n) / O(1) avg (unordered) |
| `size` / `empty`    | Size and emptiness check             | O(1)                           |
| `clear`             | Clear all elements                   | O(n)                           |
| `swap`              | Swap contents with another set       | O(1)                           |
| Iterators           | Access elements using iterators      | O(1) per step                  |

---

