# Copy() Vs Deepcopy() Methods
In Python, the `copy()` and `deepcopy()` methods are used to create copies of objects. However, they differ in how they handle mutable objects and nested data structures.

### 1. `copy()`

The `copy()` method creates a shallow copy of an object. This means that it creates a new object, but it does not recursively copy the objects contained within the original object. Instead, it copies references to those nested objects. Consequently, if the original object contains mutable objects (like lists or dictionaries), changes to those mutable objects in the copy will also affect the original.

#### Example of `copy()`

```python
import copy

# Original list with nested mutable objects
original_list = [1, 2, [3, 4]]

# Create a shallow copy of the original list
shallow_copy = copy.copy(original_list)

# Modify the nested list in the shallow copy
shallow_copy[2][0] = 'Changed'

print("Original List:", original_list)  # Output: [1, 2, ['Changed', 4]]
print("Shallow Copy:", shallow_copy)     # Output: [1, 2, ['Changed', 4]]
```

#### Output
```
Original List: [1, 2, ['Changed', 4]]
Shallow Copy: [1, 2, ['Changed', 4]]
```

In this example:
- Changing the nested list in `shallow_copy` affects `original_list` because both lists reference the same nested list.

### 2. `deepcopy()`

The `deepcopy()` method creates a deep copy of an object, meaning it recursively copies all nested objects as well. This ensures that the new object is completely independent of the original object, including all its nested objects.

#### Example of `deepcopy()`

```python
import copy

# Original list with nested mutable objects
original_list = [1, 2, [3, 4]]

# Create a deep copy of the original list
deep_copy = copy.deepcopy(original_list)

# Modify the nested list in the deep copy
deep_copy[2][0] = 'Changed'

print("Original List:", original_list)  # Output: [1, 2, [3, 4]]
print("Deep Copy:", deep_copy)           # Output: [1, 2, ['Changed', 4]]
```

#### Output
```
Original List: [1, 2, [3, 4]]
Deep Copy: [1, 2, ['Changed', 4]]
```

In this example:
- Changing the nested list in `deep_copy` does not affect `original_list`, as `deepcopy()` creates a completely independent copy of all nested objects.

### Summary of Differences

| Feature                   | `copy()`                  | `deepcopy()`                   |
|---------------------------|---------------------------|--------------------------------|
| Type of Copy              | Shallow copy              | Deep copy                      |
| Nested Objects             | References to original objects | Copies of original objects    |
| Independence              | Not independent (shared references) | Independent                    |
| Performance               | Faster, less memory usage | Slower, more memory usage due to recursion |

### When to Use

- **Use `copy()`** when you only need a copy of the object without needing to duplicate nested mutable objects.
- **Use `deepcopy()`** when you require a completely independent copy, especially when working with complex, nested data structures where changes to nested objects in one copy should not affect the other.

### Key Points 

- **Shallow vs. Deep Copy**: Understand the difference between shallow and deep copies, especially in the context of mutable objects.
- **Copying Nested Structures**: Know how `copy()` affects nested objects and why `deepcopy()` is needed for full independence.
- **Importing the Module**: Remember to import the `copy` module to use these functions.

By understanding the distinction between `copy()` and `deepcopy()`, you can effectively manage object references and avoid unintended side effects when manipulating data in Python.
