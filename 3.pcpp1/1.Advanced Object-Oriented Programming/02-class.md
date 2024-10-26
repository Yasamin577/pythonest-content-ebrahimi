# Class
Understanding essential terminology in Python is crucial for tackling advanced programming concepts. Here’s a breakdown of key terms, each with an example.

### 1. **Namespace**
A *namespace* is a container where names (identifiers) are mapped to objects. It ensures that variable names in different parts of a program do not interfere with each other. Python has several namespaces: local, global, and built-in.

```python
# Global namespace
x = "Global X"

def func():
    # Local namespace
    x = "Local X"
    print(x)

func()          # Outputs "Local X"
print(x)        # Outputs "Global X"
```

Here, `x` in `func()` is in the local namespace, while `x` outside is in the global namespace.

### 2. **Scope**
*Scope* defines where a particular variable or identifier is accessible. Python has four types of scope (LEGB rule): Local, Enclosing, Global, and Built-in.

```python
def outer():
    x = "Enclosing X"
    def inner():
        x = "Local X"
        print(x)
    inner()

outer()  # Outputs "Local X"
```

Python looks for a variable in the Local, Enclosing, Global, and Built-in scopes, in that order.

### 3. **Mutable vs Immutable Objects**
*Mutable objects* (e.g., lists, dictionaries) can be modified after creation, while *immutable objects* (e.g., strings, tuples) cannot be changed.

```python
# Immutable
name = "John"
name = name.replace("J", "T")  # Creates a new string

# Mutable
colors = ["red", "blue"]
colors.append("green")  # Modifies the original list
```

### 4. **Shallow Copy vs Deep Copy**
A *shallow copy* copies references of objects, whereas a *deep copy* creates an entirely independent copy of objects, including nested ones.

```python
import copy

original = [[1, 2], [3, 4]]
shallow_copy = copy.copy(original)
deep_copy = copy.deepcopy(original)

original[0][0] = 9
print(shallow_copy)  # [[9, 2], [3, 4]] - affected
print(deep_copy)     # [[1, 2], [3, 4]] - unaffected
```

### 5. **Generator**
A *generator* is a special function that yields items one at a time using the `yield` keyword, which is efficient for large data sets.

```python
def countdown(n):
    while n > 0:
        yield n
        n -= 1

for i in countdown(5):
    print(i)
```

Generators do not store values in memory; they produce them on demand.

### 6. **Decorator**
A *decorator* is a function that takes another function and extends its behavior without modifying its structure.

```python
def my_decorator(func):
    def wrapper():
        print("Something before the function.")
        func()
        print("Something after the function.")
    return wrapper

@my_decorator
def say_hello():
    print("Hello!")

say_hello()
```

Here, `@my_decorator` adds additional functionality around `say_hello()`.

### 7. **Context Manager**
A *context manager* manages resources (e.g., file handling) and is implemented using the `with` statement, along with `__enter__` and `__exit__` methods for setup and teardown.

```python
with open("example.txt", "w") as file:
    file.write("Hello, World!")
```

Using `with open(...)` ensures that the file is automatically closed after use.

### 8. **List Comprehension**
*List comprehension* provides a concise way to create lists based on existing lists or ranges.

```python
squares = [x**2 for x in range(10)]
print(squares)
```

This creates a list of squares from `0` to `9`.

### 9. **Lambda Function**
A *lambda function* is a small, anonymous function that can take any number of arguments but only one expression.

```python
double = lambda x: x * 2
print(double(5))  # Outputs 10
```

Lambda functions are often used in cases where a small function is required for a short time.

### 10. **Duck Typing**
*Duck typing* in Python means that the type of an object is determined by its behavior (methods and properties) rather than its explicit type.

```python
class Duck:
    def quack(self):
        print("Quack!")

class Person:
    def quack(self):
        print("I'm pretending to be a duck!")

def make_it_quack(duck):
    duck.quack()

d = Duck()
p = Person()
make_it_quack(d)  # Outputs "Quack!"
make_it_quack(p)  # Outputs "I'm pretending to be a duck!"
```

Python checks if `duck` has a `quack()` method, regardless of its class.

### 11. **Metaclass**
A *metaclass* is a "class of a class," which defines the behavior of classes. It is used to modify class creation and is an advanced concept in OOP.

```python
class Meta(type):
    def __new__(cls, name, bases, dct):
        print("Creating a new class with metaclass Meta")
        return super().__new__(cls, name, bases, dct)

class MyClass(metaclass=Meta):
    pass
```

Creating `MyClass` invokes `Meta`’s `__new__` method.

### 12. **MRO (Method Resolution Order)**
The *Method Resolution Order* determines the order in which classes are inherited, especially when using multiple inheritance. Python follows the C3 linearization algorithm.

```python
class A:
    def show(self):
        print("A")

class B(A):
    def show(self):
        print("B")

class C(A):
    def show(self):
        print("C")

class D(B, C):
    pass

print(D.__mro__)  # Shows the MRO for class D
```

### 13. **Iterator vs Iterable**
An *iterable* is an object that can return an iterator, while an *iterator* is an object with `__next__()` and `__iter__()` methods.

```python
my_list = [1, 2, 3]
iterator = iter(my_list)  # Converts iterable to iterator

print(next(iterator))  # Outputs 1
print(next(iterator))  # Outputs 2
```

### 14. **Polymorphism**
*Polymorphism* allows objects of different types to be used interchangeably, based on shared behavior (methods) rather than shared inheritance.

```python
class Dog:
    def speak(self):
        return "Woof!"

class Cat:
    def speak(self):
        return "Meow!"

def make_sound(animal):
    print(animal.speak())

make_sound(Dog())  # Outputs "Woof!"
make_sound(Cat())  # Outputs "Meow!"
```

### 15. **Type Hinting**
*Type hinting* is a feature that allows you to specify the expected types of variables, parameters, and return values, improving readability and debugging.

```python
def greet(name: str) -> str:
    return "Hello, " + name

print(greet("Alice"))
```

