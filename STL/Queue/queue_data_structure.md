# Queue and Related Data Types in C++

This markdown provides a comprehensive overview of the `queue` data structure and its related types, including their algorithms, use cases, and complexities. It serves as a helpful reference for interview preparation and understanding.

---

## Introduction to Queues

A **queue** is a linear data structure that follows the **FIFO** (First In, First Out) principle. Elements are added at the back (enqueue) and removed from the front (dequeue). Queues are widely used in scheduling, buffering, and resource-sharing scenarios.

### Characteristics:
- Elements are processed in the order they arrive.
- Supports sequential access only.
- Primary operations include:
  - **`push`**: Adds an element to the back.
  - **`pop`**: Removes an element from the front.
  - **`front`**: Accesses the first element.
  - **`empty`**: Checks if the queue is empty.

---

## Types of Queues

### 1. **Standard Queue (`std::queue`)**
- A simple FIFO structure.
- Built on top of a container like `std::deque` or `std::list`.

### 2. **Priority Queue (`std::priority_queue`)**
- Stores elements in a heap-like structure.
- Elements are ordered by priority, with the highest priority element at the front.

### 3. **Double-Ended Queue (`std::deque`)**
- Allows insertion and deletion from both ends.
- More versatile but heavier in memory usage compared to a standard queue.

### 4. **Circular Queue (can use vector ds) **
- Implements a fixed-size queue in a circular buffer.
- Efficient for low-memory scenarios.

### 5. **Blocking Queue (can use queue ds)**
- Blocks operations if the queue is empty (on dequeue) or full (on enqueue).
- Commonly used in multi-threaded systems.

---

## Common Methods for Queues

### 1. `push`
Adds an element to the back of the queue.

#### Syntax:
```cpp
q.push(val);
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Add Element         | O(1)           |

---

### 2. `pop`
Removes the element from the front of the queue.

#### Syntax:
```cpp
q.pop();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Remove Element      | O(1)           |

---

### 3. `front`
Accesses the first element of the queue.

#### Syntax:
```cpp
auto first = q.front();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Access Front        | O(1)           |

---

### 4. `back`
Accesses the last element of the queue.

#### Syntax:
```cpp
auto last = q.back();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Access Back         | O(1)           |

---

### 5. `size`
Returns the number of elements in the queue.

#### Syntax:
```cpp
size_t sz = q.size();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Get Size            | O(1)           |

---

### 6. `empty`
Checks if the queue is empty.

#### Syntax:
```cpp
bool isEmpty = q.empty();
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Check Empty         | O(1)           |

---

### 7. `emplace`
Constructs and inserts an element at the back of the queue (for `std::queue`).

#### Syntax:
```cpp
q.emplace(args...);
```
#### Complexity:
| Operation           | Time Complexity |
|---------------------|-----------------|
| Emplace Element     | O(1)           |

---

### Additional Methods for `std::deque`:

#### 8. `push_front` / `pop_front`
- Adds or removes elements from the front.
- **Syntax:**
  ```cpp
  dq.push_front(val);
  dq.pop_front();
  ```
- **Complexity:** O(1).

#### 9. `push_back` / `pop_back`
- Adds or removes elements from the back.
- **Syntax:**
  ```cpp
  dq.push_back(val);
  dq.pop_back();
  ```
- **Complexity:** O(1).

#### 10. `at`
- Accesses the element at a specific index.
- **Syntax:**
  ```cpp
  auto elem = dq.at(index);
  ```
- **Complexity:** O(1).

---

## Summary of Queue Types and Complexities

| Queue Type              | Use Case                                         | Time Complexity (Enqueue/Dequeue) |
|-------------------------|--------------------------------------------------|------------------------------------|
| `std::queue`            | FIFO operations                                  | O(1)                              |
| `std::priority_queue`   | Order elements by priority                       | O(log n)                          |
| `std::deque`            | Double-ended operations                         | O(1)                              |
| Circular Queue          | Fixed-size circular buffer                      | O(1)                              |
| Blocking Queue          | Multi-threaded scenarios                        | Depends on implementation         |

