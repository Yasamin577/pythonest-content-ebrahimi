# Magic Methods
In Python, **magic methods** (also known as dunder methods because they have double underscores before and after their names) allow you to define how objects of a class should behave with built-in operations, such as addition, comparison, string representation, and more. They provide a way to implement custom behavior for many operators and functions, making your classes more intuitive and Pythonic.

Magic methods are called automatically when an operation involving your class is performed. Here are some of the most common magic methods and examples to illustrate their usage.

### Common Magic Methods

1. **`__init__()`**: Initializes a new instance of a class.
2. **`__str__()`** and **`__repr__()`**: Define string representations.
3. **`__add__()`, `__sub__()`, `__mul__()`**: Allow instances to use arithmetic operators.
4. **`__len__()`**: Returns the length.
5. **`__getitem__()`, `__setitem__()`**: Allow indexing and assignment.
6. **`__eq__()`, `__lt__()`, `__gt__()`**: Implement comparison operations.

Let’s explore each with examples.

### 1. `__init__()`: Initialization

`__init__` is a constructor method that initializes an instance with specific attributes when it is created.

```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

point = Point(3, 4)
print(point.x, point.y)  # Outputs: 3 4
```

### 2. `__str__()` and `__repr__()`: String Representation

- `__str__()` is called by `print()` or `str()` and should return a readable string for users.
- `__repr__()` is for developers, showing an unambiguous string representation of the object.

```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"Point({self.x}, {self.y})"

    def __repr__(self):
        return f"Point({self.x}, {self.y})"

point = Point(3, 4)
print(point)             # Outputs: Point(3, 4)
print(repr(point))       # Outputs: Point(3, 4)
```

### 3. Arithmetic Magic Methods (`__add__()`, `__sub__()`, `__mul__()`, etc.)

These methods let you define behavior for arithmetic operations. For example, `__add__()` defines the behavior for the `+` operator.

```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __str__(self):
        return f"Point({self.x}, {self.y})"

point1 = Point(1, 2)
point2 = Point(3, 4)
result = point1 + point2
print(result)  # Outputs: Point(4, 6)
```

Here, we defined `__add__()` to enable the addition of two `Point` objects.

### 4. `__len__()`: Length

The `__len__()` method allows you to define behavior for the `len()` function.

```python
class Line:
    def __init__(self, length):
        self.length = length

    def __len__(self):
        return self.length

line = Line(10)
print(len(line))  # Outputs: 10
```

### 5. `__getitem__()` and `__setitem__()`: Indexing and Assignment

These methods let you make objects that can be accessed like lists or dictionaries.

```python
class Storage:
    def __init__(self):
        self.data = {}

    def __getitem__(self, key):
        return self.data[key]

    def __setitem__(self, key, value):
        self.data[key] = value

storage = Storage()
storage["item"] = "Value"
print(storage["item"])  # Outputs: Value
```

### 6. Comparison Magic Methods (`__eq__()`, `__lt__()`, `__gt__()`, etc.)

Comparison methods allow you to define behavior for comparison operators, like `==`, `<`, and `>`.

```python
class Person:
    def __init__(self, age):
        self.age = age

    def __eq__(self, other):
        return self.age == other.age

    def __lt__(self, other):
        return self.age < other.age

person1 = Person(25)
person2 = Person(30)
print(person1 == person2)   # Outputs: False
print(person1 < person2)    # Outputs: True
```

### Other Useful Magic Methods

- **`__call__()`**: Makes an object callable as a function.
- **`__enter__()` and `__exit__()`**: Implement context managers, used with `with` statements.

### Example Combining Multiple Magic Methods

Here’s a class with multiple magic methods:

```python
class BankAccount:
    def __init__(self, balance=0):
        self.balance = balance

    def __str__(self):
        return f"Balance: ${self.balance}"

    def __add__(self, amount):
        self.balance += amount
        return self

    def __sub__(self, amount):
        self.balance -= amount
        return self

    def __eq__(self, other):
        return self.balance == other.balance

account1 = BankAccount(100)
account2 = BankAccount(100)
print(account1 + 50)         # Outputs: Balance: $150
print(account1 - 30)         # Outputs: Balance: $120
print(account1 == account2)  # Outputs: False
```

### Key Points 

- **Purpose of Magic Methods**: Understand how magic methods customize default behaviors.
- **Common Magic Methods**: Know how to implement frequently used methods like `__init__`, `__str__`, `__add__`, and `__eq__`.
- **Operator Overloading**: Magic methods allow operator overloading, meaning you can redefine operators (`+`, `-`, `==`, etc.) for custom classes.

Magic methods are essential in Python for defining custom behaviors and making your classes behave intuitively with built-in functions and operators.
