# Extended Function
In Python, an *extended function* refers to a function that builds upon or modifies an existing function’s behavior. This can be achieved through several techniques, such as:

1. **Function Wrapping (Decorator Pattern)**: Using a wrapper function to extend functionality.
2. **Inheritance and Method Overriding**: Extending or modifying a function in a subclass.
3. **Extending Built-in Functions or Classes**: Modifying built-in functions by creating custom versions or using decorators.

Let’s go over each approach with examples.

---

### 1. Extending a Function with a Wrapper (Decorators)

Decorators are a common way to extend a function’s behavior without modifying its original code. A decorator is a function that takes another function as input, extends or alters its functionality, and returns the extended function.

**Example**: Adding Logging to a Function

```python
def log_decorator(func):
    def wrapper(*args, **kwargs):
        print(f"Calling {func.__name__} with arguments {args} and {kwargs}")
        result = func(*args, **kwargs)
        print(f"{func.__name__} returned {result}")
        return result
    return wrapper

@log_decorator
def add(x, y):
    return x + y

# Using the extended function
print(add(3, 4))
```

#### Output
```
Calling add with arguments (3, 4) and {}
add returned 7
7
```

In this example:
- The `log_decorator` adds logging functionality to the `add()` function without altering `add()`’s original code.
- This is a powerful technique to extend functions in Python by wrapping them with additional functionality.

---

### 2. Extending Functionality Using Inheritance and Method Overriding

When you have a class with a method that you want to extend or modify, inheritance and method overriding allow you to add functionality to the method in a subclass.

**Example**: Extending a Method in a Subclass

```python
class Animal:
    def sound(self):
        return "Some sound"

class Dog(Animal):
    def sound(self):
        original_sound = super().sound()  # Calling the superclass method
        return f"{original_sound} - Woof!"

# Using the extended method
dog = Dog()
print(dog.sound())
```

#### Output
```
Some sound - Woof!
```

In this example:
- The `Dog` class inherits the `sound()` method from the `Animal` class and extends it by adding “Woof!” to the original sound.
- The `super().sound()` call in the subclass allows you to leverage the original method while extending its behavior.

---

### 3. Extending Built-in Functions

Sometimes you may need to extend built-in functions by creating custom versions that add extra functionality. You can achieve this by defining new functions that incorporate built-in functionality and additional logic.

**Example**: Extending the Built-in `print()` Function

```python
def custom_print(*args, prefix="INFO:", **kwargs):
    print(prefix, *args, **kwargs)

# Using the extended function
custom_print("This is an important message.")
custom_print("Another message", prefix="DEBUG:")
```

#### Output
```
INFO: This is an important message.
DEBUG: Another message
```

In this example:
- We extended the functionality of `print()` by creating `custom_print()` with an optional `prefix` argument. This allows us to add a custom prefix (like "INFO:" or "DEBUG:") before each printed message.

---

### Summary of Extended Function Techniques

| Technique                 | Description                                                                     | Example Use Case                                    |
|---------------------------|---------------------------------------------------------------------------------|-----------------------------------------------------|
| Function Wrapping         | Using a decorator to add functionality to an existing function                 | Logging, caching, input validation                  |
| Inheritance and Overriding| Extending a class method in a subclass                                         | Customizing base class behavior in a subclass       |
| Extending Built-in Functions | Creating a custom function that calls a built-in function and adds new behavior | Customizing `print()` output                         |

### Key Points 

- **Decorators**: Know how to use decorators to extend functions by wrapping them.
- **Inheritance and `super()`**: Use inheritance to override and extend methods in subclasses.
- **Custom Functions**: Understand how to extend built-in functions by creating custom wrappers.

These techniques provide flexibility for modifying or enhancing existing functionality, making Python code more modular, reusable, and adaptable to evolving requirements.