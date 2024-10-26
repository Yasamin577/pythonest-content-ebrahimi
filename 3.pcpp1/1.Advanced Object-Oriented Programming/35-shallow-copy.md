# Shallow Copy
A **shallow copy** in Python is a copy of an object that copies only the top-level structure of the object, not the nested or referenced objects inside it. This means that for compound objects like lists of lists or dictionaries of dictionaries, only the outer container is copied, while the nested objects still refer to the original memory locations. 

In contrast, a **deep copy** creates an entirely independent copy of both the top-level object and any nested objects it contains.

### How to Make a Shallow Copy

In Python, you can create a shallow copy of a list or dictionary using:
- The `copy()` method of the list or dictionary.
- The `copy` module's `copy()` function.

### Example of a Shallow Copy in Python

Let’s look at a shallow copy using a list of lists to illustrate how only the outer list is copied, not the nested lists.

1. **Using the `copy` Module**

   ```python
   import copy

   # Original list of lists
   original = [[1, 2, 3], [4, 5, 6]]
   
   # Creating a shallow copy
   shallow_copied = copy.copy(original)

   # Modifying the shallow copy
   shallow_copied[0][0] = 'X'

   print("Original:", original)
   print("Shallow Copy:", shallow_copied)
   ```

   #### Output
   ```
   Original: [['X', 2, 3], [4, 5, 6]]
   Shallow Copy: [['X', 2, 3], [4, 5, 6]]
   ```

In this example:
- The change made to `shallow_copied[0][0]` also affected `original[0][0]` because both `original` and `shallow_copied` share references to the same inner lists.
- The outer list is independent, but the inner lists are still shared between `original` and `shallow_copied`.

2. **Using `list.copy()` or `dict.copy()` Methods**

   ```python
   # Using list.copy() for shallow copy
   original_list = [1, [2, 3], 4]
   shallow_copied_list = original_list.copy()

   shallow_copied_list[1][0] = 'A'

   print("Original List:", original_list)
   print("Shallow Copied List:", shallow_copied_list)
   ```

   #### Output
   ```
   Original List: [1, ['A', 3], 4]
   Shallow Copied List: [1, ['A', 3], 4]
   ```

### Explanation of Shallow Copy Behavior

In both examples, only the top-level list is copied, so `shallow_copied` is a new list object independent of `original_list`. However, any nested objects within the lists are still references to the same objects in memory. Thus, modifying an inner list in `shallow_copied` also affects `original_list`.

### When to Use Shallow Copy

Shallow copies are useful when:
1. You only need a duplicate of the outer structure, not of nested or referenced objects.
2. The nested objects will not be modified.

### Key Points 

- **Definition**: A shallow copy creates a new object but keeps references to the nested objects of the original.
- **Common Methods**: `copy.copy()` from the `copy` module, `list.copy()`, and `dict.copy()`.
- **Use Cases**: Shallow copies are efficient for duplicating outer structures when inner content does not need duplication.

Understanding shallow copy behavior is essential for managing references effectively and avoiding unintended changes in nested data structures.