# Instance And Class Variables
In Python, *instance variables* and *class variables* are two types of variables used within classes, each serving different purposes in object-oriented programming.

### 1. **Instance Variables**

*Instance variables* are variables that belong to each individual instance (object) of a class. Each object has its own unique copy of instance variables, allowing each object to store its own data.

- Defined within a method (typically `__init__`).
- Prefixed with `self`, like `self.variable_name`.
- Unique to each instance.

**Example**:
```python
class Car:
    def __init__(self, color, brand):
        self.color = color     # Instance variable
        self.brand = brand     # Instance variable

# Creating two Car instances with different instance variable values
car1 = Car("Red", "Toyota")
car2 = Car("Blue", "Honda")

print(car1.color)  # Output: Red
print(car2.color)  # Output: Blue
```

In this example, each `Car` object (`car1` and `car2`) has its own `color` and `brand` values. Changing `car1.color` doesn’t affect `car2.color` and vice versa, as each instance has its own set of instance variables.

### 2. **Class Variables**

*Class variables* are variables that belong to the class itself, not to any particular instance. They are shared across all instances of the class, meaning any change to a class variable affects all instances.

- Defined directly within the class (outside any methods).
- Prefixed with the class name (e.g., `ClassName.variable_name`) or accessed via `self`.
- Shared by all instances of the class.

**Example**:
```python
class Car:
    wheels = 4  # Class variable

    def __init__(self, color, brand):
        self.color = color     # Instance variable
        self.brand = brand     # Instance variable

car1 = Car("Red", "Toyota")
car2 = Car("Blue", "Honda")

print(car1.wheels)  # Output: 4
print(car2.wheels)  # Output: 4

# Modifying the class variable
Car.wheels = 6
print(car1.wheels)  # Output: 6 (reflects change in class variable)
print(car2.wheels)  # Output: 6
```

In this example, `wheels` is a class variable, so both `car1` and `car2` refer to the same `wheels` variable. Changing `Car.wheels` updates it across all instances of the class.

### Differences Between Instance and Class Variables

| Feature             | Instance Variables                     | Class Variables                    |
|---------------------|----------------------------------------|------------------------------------|
| Defined In          | Instance method (e.g., `__init__`)    | Directly within the class          |
| Accessed By         | `self.variable_name`                  | `ClassName.variable_name` or `self`|
| Unique to Each      | Yes, each instance has its own copy   | No, shared across all instances    |
| Lifetime            | Created when the instance is created  | Created when the class is loaded   |

### Practical Use Cases

- **Instance Variables**: Ideal for attributes that differ between objects, such as `color` or `brand` in a `Car` class.
- **Class Variables**: Useful for attributes that should be consistent across all instances, such as a constant `wheels` for all `Car` objects.

### Key Points 
- Understand that **instance variables** are unique to each object, while **class variables** are shared across instances.
- **Instance variables** are often used to store data specific to each object, and **class variables** are used for data that applies broadly to all objects of that class.
- Familiarity with when to use each type of variable is essential for effective object-oriented programming in Python.