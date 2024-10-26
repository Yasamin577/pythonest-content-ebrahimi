# Function And Class Decorators
Decorators in Python are a powerful tool that allows you to modify or enhance functions and classes without altering their actual code. Decorators take a function or class as input, wrap it in another function or class with added functionality, and return the modified function or class. 

Decorators are commonly used for logging, enforcing access control, monitoring, and modifying behavior.

### Function Decorators

A **function decorator** takes a function as an argument, adds functionality, and returns the enhanced function. Function decorators are typically defined with the `@decorator_name` syntax just above the function definition.

#### Example: Creating a Function Decorator

Suppose we want to create a decorator that logs when a function is called.

```python
def log_decorator(func):
    def wrapper(*args, **kwargs):
        print(f"Calling function {func.__name__}")
        result = func(*args, **kwargs)
        print(f"Function {func.__name__} returned {result}")
        return result
    return wrapper

@log_decorator
def add(a, b):
    return a + b

# Using the decorated function
add(5, 3)
```

#### Output
```
Calling function add
Function add returned 8
```

In this example:
- `log_decorator` is a function decorator that logs the function call and return value.
- The `add` function is wrapped by `log_decorator`, so every time `add` is called, the wrapper logs the information.

### Class Decorators

A **class decorator** works similarly but takes a class as input, modifies its behavior or attributes, and returns the modified class. Class decorators are useful for dynamically adding methods, attributes, or enforcing rules.

#### Example: Creating a Class Decorator

Suppose we want to add a timestamp attribute to any class decorated with `timestamp_decorator`.

```python
from datetime import datetime

def timestamp_decorator(cls):
    class Wrapped(cls):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            self.timestamp = datetime.now()  # Add a timestamp attribute

    return Wrapped

@timestamp_decorator
class MyClass:
    def __init__(self, name):
        self.name = name

# Creating an instance of MyClass
obj = MyClass("Example")
print(obj.name)       # Output: Example
print(obj.timestamp)  # Output: Current timestamp
```

In this example:
- `timestamp_decorator` is a class decorator that wraps `MyClass` and adds a `timestamp` attribute.
- When an instance of `MyClass` is created, it now has a `timestamp` attribute, which stores the creation time.

### Key Differences between Function and Class Decorators

| Feature              | Function Decorators                             | Class Decorators                                    |
|----------------------|-------------------------------------------------|-----------------------------------------------------|
| Input                | A function                                      | A class                                             |
| Common Use Cases     | Logging, access control, modifying function behavior | Adding attributes, enforcing class rules             |
| Syntax               | `@decorator_name` before function definition    | `@decorator_name` before class definition           |
| Example Output       | Returns a wrapped function                      | Returns a wrapped class                             |

### Practical Use Cases

- **Function Decorators**: 
  - Authentication checks (ensuring a user is logged in).
  - Caching function results for efficiency.
  - Logging function calls and performance metrics.
  
- **Class Decorators**:
  - Adding additional attributes or methods.
  - Enforcing singleton patterns (ensuring only one instance of a class exists).
  - Adding metadata or initializing configurations for classes.

### Advanced Example: Using Decorators for Access Control

Suppose you want to restrict a function so it only runs if the user is an admin.

```python
def admin_only(func):
    def wrapper(*args, **kwargs):
        if kwargs.get("is_admin", False):
            return func(*args, **kwargs)
        else:
            print("Access denied: Admins only")
    return wrapper

@admin_only
def restricted_function():
    print("Welcome, admin!")

restricted_function(is_admin=True)   # Output: Welcome, admin!
restricted_function(is_admin=False)  # Output: Access denied: Admins only
```

### Key Points 

- **Decorators with Arguments**: Understand how to create decorators that accept arguments.
- **Multiple Decorators**: Know how to stack multiple decorators on a function or class.
- **Class Wrapping**: Recognize how class decorators wrap classes to modify or add functionality dynamically.
- **Practical Use Cases**: Familiarize yourself with common uses for decorators, such as logging, enforcing access, caching, and adding metadata.

Decorators are a versatile and powerful feature in Python, enabling you to enhance functionality dynamically, making them invaluable for writing clean and efficient code in advanced Python programming.