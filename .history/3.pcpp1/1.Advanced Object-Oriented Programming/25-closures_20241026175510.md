# Closures
A *closure* in Python is a function that captures the local variables from its enclosing scope. Closures are created when a nested function (an inner function) remembers the environment in which it was created, even after the outer function has finished execution. Closures are useful for maintaining a state between function calls without using global variables or classes.

### Key Characteristics of Closures

1. A closure must have a nested function.
2. The nested function must refer to a variable defined in its enclosing scope.
3. The enclosing function must return the nested function.

### Why Use Closures?

Closures are often used to create functions with behavior dependent on their initial environment, such as when implementing decorators, creating factories, or managing persistent state in functions without using global variables.

### Example of a Closure

Let’s create a closure that generates a function to add a specific number to its argument. This is an example of using closures to "remember" a state.

```python
def make_adder(x):
    def adder(y):
        return x + y  # x is captured from the enclosing scope
    return adder

# Creating a closure with x = 5
add_five = make_adder(5)

# Using the closure
print(add_five(10))  # Output: 15
print(add_five(3))   # Output: 8
```

In this example:
- `make_adder` is the outer function that takes `x` as an argument.
- Inside `make_adder`, we define `adder`, a nested function that adds `x` to its argument `y`.
- When `make_adder(5)` is called, it returns the `adder` function, which retains `x = 5` from the outer scope. The returned function `add_five` acts as a closure with `x = 5` permanently in memory.
- Calling `add_five(10)` returns `15` because it adds `5 + 10`.

### How Closures Work

When the `adder` function is returned from `make_adder`, it still has access to the variable `x`, even though `make_adder` has completed execution. This is because `x` is "enclosed" within the returned `adder` function, forming a closure.

### Practical Uses of Closures

1. **Data Encapsulation**: Closures can encapsulate and hide data, which can be particularly useful for restricting access to certain variables.

   ```python
   def counter():
       count = 0
       def increment():
           nonlocal count
           count += 1
           return count
       return increment

   # Creating a closure for counting
   counter_instance = counter()
   print(counter_instance())  # Output: 1
   print(counter_instance())  # Output: 2
   print(counter_instance())  # Output: 3
   ```

   Here, `counter` is a closure that maintains its own internal `count` state across multiple calls to `increment`, but `count` is not accessible from outside `counter`.

2. **Factory Functions**: Closures are often used to create factory functions that configure functions on the fly.

   ```python
   def make_multiplier(factor):
       def multiplier(number):
           return number * factor
       return multiplier

   double = make_multiplier(2)
   triple = make_multiplier(3)

   print(double(5))  # Output: 10
   print(triple(5))  # Output: 15
   ```

3. **Decorators**: Closures are fundamental to creating decorators, which modify or extend the behavior of other functions dynamically.

### Key Points 

- **Definition and Creation**: A closure occurs when a nested function retains access to variables from its enclosing scope.
- **Use Cases**: Understand when and why to use closures, especially for data encapsulation and creating configurable functions.
- **Persistent State**: Closures allow functions to remember state between calls without global variables.
- **Practical Examples**: Closures are frequently used in Python for decorators and factory functions.

Closures are powerful in Python because they combine the functionality of functions with the persistence of variables, making them ideal for managing states and implementing encapsulation. Understanding closures is essential for advanced Python programming and is particularly relevant in functional programming scenarios.