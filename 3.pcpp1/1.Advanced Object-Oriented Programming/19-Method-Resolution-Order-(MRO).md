# Method Resolution Order (Mro)
**Method Resolution Order (MRO)** in Python is the order in which a class hierarchy is traversed when searching for a method or attribute. Python uses MRO to decide which method to call when a method is invoked on an instance of a class that has multiple ancestors. This is particularly important in multiple inheritance scenarios where ambiguity can arise about which superclass's method to use.

Python follows the **C3 Linearization** algorithm to determine the MRO. This ensures a consistent and predictable method lookup order. You can view the MRO of a class using the `.__mro__` attribute or the `mro()` method.

### Key Rules of MRO

1. **Depth-First, Left-to-Right**: Python checks each class in the order they are listed in the class declaration, from left to right.
2. **No Repetition of a Class**: Once a class has been checked, it’s not rechecked further in the MRO.
3. **Base Class is Always Last**: The root class (`object`) appears last in the MRO.

### Example: Single Inheritance

In simple inheritance, MRO is straightforward:

```python
class A:
    def show(self):
        print("A's show method")

class B(A):
    pass

class C(B):
    pass

obj = C()
obj.show()  # Outputs: "A's show method"

# Viewing MRO
print(C.__mro__)
```

#### Output
```
A's show method
(<class '__main__.C'>, <class '__main__.B'>, <class '__main__.A'>, <class 'object'>)
```

In this example, `C` inherits from `B`, which in turn inherits from `A`. Python checks `C`, then `B`, then `A`, and finally `object` if it hasn’t found the method by then.

### Example: Multiple Inheritance

With multiple inheritance, MRO becomes more complex. Consider the following scenario:

```python
class X:
    def show(self):
        print("X's show method")

class Y:
    def show(self):
        print("Y's show method")

class Z(X, Y):
    pass

obj = Z()
obj.show()  # Outputs: "X's show method"

# Viewing MRO
print(Z.__mro__)
```

#### Output
```
X's show method
(<class '__main__.Z'>, <class '__main__.X'>, <class '__main__.Y'>, <class 'object'>)
```

Here, `Z` inherits from both `X` and `Y`. According to Python's MRO (C3 Linearization):
1. Python starts with `Z`.
2. It moves to `X` (the left-most parent class).
3. Then it moves to `Y`, and finally to the `object` class.

Since `X` appears before `Y` in the MRO, `X`’s `show` method is called.

### Example: Complex Multiple Inheritance

Let’s look at a more complex example to see how MRO handles ambiguity with multiple levels of inheritance:

```python
class A:
    def show(self):
        print("A's show method")

class B(A):
    def show(self):
        print("B's show method")

class C(A):
    def show(self):
        print("C's show method")

class D(B, C):
    pass

obj = D()
obj.show()  # Outputs: "B's show method"

# Viewing MRO
print(D.__mro__)
```

#### Output
```
B's show method
(<class '__main__.D'>, <class '__main__.B'>, <class '__main__.C'>, <class '__main__.A'>, <class 'object'>)
```

In this example:
1. Python starts with `D`.
2. Then it moves to `B` (the first superclass in `D(B, C)`).
3. Next, it checks `C`, then `A`, and finally `object`.

Since `B` appears before `C` in `D`'s MRO, `B`'s `show` method is called.

### Viewing the MRO

You can view the MRO in three main ways:
1. Using `.__mro__` attribute:
   ```python
   print(D.__mro__)
   ```

2. Using the `mro()` method:
   ```python
   print(D.mro())
   ```

3. Using `help()`:
   ```python
   help(D)
   ```

### Key Points 

- **MRO Concept**: MRO determines the order in which Python looks for methods in a class hierarchy.
- **C3 Linearization**: Python follows the C3 linearization algorithm, which ensures a consistent lookup order, especially in multiple inheritance.
- **Viewing MRO**: Know how to view the MRO using `.__mro__`, `.mro()`, or `help()`.
- **Multiple Inheritance Rules**: Understand that MRO checks classes from left to right in the inheritance declaration, and that the base class `object` is always last.

Understanding MRO is essential when working with multiple inheritance, as it affects which method gets called and ensures your code follows Python’s inheritance rules correctly.
