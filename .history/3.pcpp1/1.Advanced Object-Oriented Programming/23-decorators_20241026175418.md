# Decorators
In Python, **decorators** are a way to modify or extend the behavior of a function or method without changing its code. Decorators wrap another function in order to add some functionality before or after the original function is executed. They are commonly used for logging, access control, timing functions, and more.

### How Decorators Work

Decorators are functions that take another function as an argument, add some behavior, and then return a new function. The `@decorator_name` syntax is a shorthand way to apply a decorator to a function.

### Basic Structure of a Decorator

A decorator function typically:
1. Takes a function as an argument.
2. Defines an inner function (wrapper) that modifies or adds behavior.
3. Calls the original function within this inner function.
4. Returns the inner function.

### Example: Basic Decorator

Here’s a simple decorator that adds a message before and after the execution of a function:

1. **Define the Decorator**

   ```python
   def my_decorator(func):
       def wrapper():
           print("Something before the function.")
           func()  # Call the original function
           print("Something after the function.")
       return wrapper
   ```

2. **Using the Decorator**

   You can apply the decorator to a function using the `@` syntax:

   ```python
   @my_decorator
   def say_hello():
       print("Hello!")

   say_hello()
   ```

   #### Output
   ```
   Something before the function.
   Hello!
   Something after the function.
   ```

In this example:
- `my_decorator` wraps `say_hello`.
- When `say_hello` is called, it executes the additional print statements defined in the `wrapper` function, providing extra functionality around the original function.

### How Decorators with Arguments Work

If the original function takes arguments, the decorator's wrapper function should accept `*args` and `**kwargs` to pass them correctly.

1. **Decorator with Arguments**

   Here’s an example of a decorator that accepts arguments:

   ```python
   def my_decorator(func):
       def wrapper(*args, **kwargs):
           print("Function arguments:", args, kwargs)
           result = func(*args, **kwargs)
           print("Function executed.")
           return result
       return wrapper
   ```

2. **Applying the Decorator**

   ```python
   @my_decorator
   def add(a, b):
       return a + b

   print(add(3, 5))
   ```

   #### Output
   ```
   Function arguments: (3, 5) {}
   Function executed.
   8
   ```

Here, `my_decorator` can handle functions with parameters, logging the arguments and result.

### Practical Use Cases for Decorators

#### 1. **Logging**
   Decorators are often used to log function calls and their parameters.

   ```python
   def log_function(func):
       def wrapper(*args, **kwargs):
           print(f"Calling {func.__name__} with arguments {args} and {kwargs}")
           return func(*args, **kwargs)
       return wrapper

   @log_function
   def multiply(x, y):
       return x * y

   multiply(2, 3)
   ```

   Output:
   ```
   Calling multiply with arguments (2, 3) and {}
   6
   ```

#### 2. **Access Control**
   Decorators can check user permissions or access levels before allowing access to certain functions.

   ```python
   def requires_permission(func):
       def wrapper(*args, **kwargs):
           if not user_has_permission:
               print("Access denied.")
               return
           return func(*args, **kwargs)
       return wrapper

   user_has_permission = False  # Change this to True to allow access

   @requires_permission
   def access_sensitive_data():
       print("Accessing sensitive data.")

   access_sensitive_data()
   ```

#### 3. **Timing Functions**
   Decorators can time the execution of a function for performance monitoring.

   ```python
   import time

   def timer(func):
       def wrapper(*args, **kwargs):
           start_time = time.time()
           result = func(*args, **kwargs)
           end_time = time.time()
           print(f"{func.__name__} took {end_time - start_time:.4f} seconds")
           return result
       return wrapper

   @timer
   def slow_function():
       time.sleep(1)
       print("Function finished.")

   slow_function()
   ```

   Output:
   ```
   Function finished.
   slow_function took 1.0001 seconds
   ```

### Key Points 

- **Decorator Structure**: Understand that a decorator wraps a function, allowing additional code to run before or after the wrapped function.
- **Decorator with Arguments**: Be comfortable writing decorators that handle functions with parameters using `*args` and `**kwargs`.
- **Practical Applications**: Familiarize yourself with common use cases, such as logging, access control, and performance measurement.
- **Applying Multiple Decorators**: Multiple decorators can be applied to a function in sequence.

Decorators provide powerful and flexible ways to extend functionality, making them invaluable for writing clean, reusable, and maintainable Python code. Let me know if you’d like more depth on any specific use case!