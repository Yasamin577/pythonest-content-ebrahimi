# Deep Copy
In Python, a **deep copy** refers to creating a new object that is a complete copy of another object, including all the nested objects contained within it. This means that changes made to the original object or its nested objects will not affect the deep copy, and vice versa.

Deep copying is especially important when working with compound objects (like lists or dictionaries) that contain other mutable objects (like lists, sets, or dictionaries). The built-in `copy` module provides a convenient way to create deep copies using the `deepcopy()` function.

### Key Characteristics of Deep Copy
- Creates a new object.
- Copies all objects recursively, including nested objects.
- Modifications to the original object do not affect the deep copy.

### How to Create a Deep Copy

1. **Import the `copy` Module**: To use the `deepcopy()` function.
2. **Use `copy.deepcopy()`**: Call this function to create a deep copy of the original object.

### Example: Using Deep Copy

Let's illustrate deep copying with a practical example.

1. **Create a Nested List**

   ```python
   import copy

   # Original list containing nested lists
   original_list = [1, 2, [3, 4], 5]

   # Create a deep copy of the original list
   deep_copied_list = copy.deepcopy(original_list)
   ```

2. **Modify the Original List**

   Now, let's modify the nested list in the original list and see how it affects the deep copy.

   ```python
   # Modifying the original list
   original_list[2][0] = "Changed"

   print("Original List:", original_list)          # Outputs: Original List: [1, 2, ['Changed', 4], 5]
   print("Deep Copied List:", deep_copied_list)   # Outputs: Deep Copied List: [1, 2, [3, 4], 5]
   ```

   In this example:
   - The original list `original_list` contains a nested list `[3, 4]`.
   - After changing the first element of the nested list in `original_list` to `"Changed"`, the `deep_copied_list` remains unaffected. This demonstrates that the deep copy is independent of the original.

### Shallow Copy vs. Deep Copy

To understand deep copy better, it's useful to contrast it with a **shallow copy**. A shallow copy creates a new object but does not create copies of nested objects; instead, it copies references to those nested objects.

Here’s how to create a shallow copy using the `copy` module:

```python
import copy

# Create a shallow copy of the original list
shallow_copied_list = copy.copy(original_list)

# Modify the original nested list
original_list[2][0] = "Changed Again"

print("Original List:", original_list)            # Outputs: Original List: [1, 2, ['Changed Again', 4], 5]
print("Shallow Copied List:", shallow_copied_list) # Outputs: Shallow Copied List: [1, 2, ['Changed Again', 4], 5]
```

In this example:
- Changing the nested list in `original_list` also affects `shallow_copied_list`, demonstrating that shallow copies share references to nested objects.

### When to Use Deep Copy

- **Complex Data Structures**: Use deep copy when working with nested structures, like lists of lists or dictionaries of lists, where you need to ensure complete independence between copies.
- **Data Integrity**: If you need to preserve the state of the original object while making modifications, deep copy is the way to go.

### Key Points 

- **Definition**: A deep copy creates a new object and recursively copies all nested objects, ensuring independence from the original.
- **Usage**: Use `copy.deepcopy()` to create deep copies in Python.
- **Contrast with Shallow Copy**: Understand the difference between shallow and deep copies, especially regarding nested mutable objects.

Deep copying is a crucial concept in Python for managing complex data structures and ensuring that modifications to one object do not inadvertently affect another.
