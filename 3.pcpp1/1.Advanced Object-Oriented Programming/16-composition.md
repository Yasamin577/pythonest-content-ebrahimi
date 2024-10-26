# Composition
**Composition** in Python is an Object-Oriented Programming concept where a class is built using objects from other classes, establishing a "has-a" relationship instead of an "is-a" relationship (as with inheritance). In composition, one class contains an instance of another class and uses its functionality as needed, allowing for more flexible and modular design.

### Key Idea of Composition
In composition:
- A class (often referred to as the *container class*) contains objects of other classes as attributes.
- The container class does not inherit from these other classes but instead uses their instances to perform tasks.

### When to Use Composition
Composition is helpful when:
- You want to reuse code without creating a strict parent-child relationship.
- The relationship between objects is a "has-a" relationship rather than "is-a."

For example, a `Car` class might *have a* `Engine` class rather than *be an* `Engine`.

### Example of Composition in Python

Let's create a `Book` class and an `Author` class using composition, where each `Book` object has an `Author` object as an attribute.

1. **Defining the `Author` Class**

   ```python
   class Author:
       def __init__(self, name, nationality):
           self.name = name
           self.nationality = nationality

       def get_details(self):
           return f"{self.name}, {self.nationality}"
   ```

   The `Author` class holds information about an author, such as their `name` and `nationality`, and provides a method `get_details()`.

2. **Defining the `Book` Class Using Composition**

   In the `Book` class, we include an `Author` object as an attribute, representing the composition relationship.

   ```python
   class Book:
       def __init__(self, title, author):
           self.title = title
           self.author = author  # Composition: Book "has an" Author

       def get_book_info(self):
           return f"'{self.title}' by {self.author.get_details()}"
   ```

   Here, the `Book` class contains an `Author` instance as an attribute, enabling it to access the `get_details()` method from the `Author` class.

3. **Using Composition**

   Now, we can create an instance of `Author` and use it in the `Book` class:

   ```python
   # Creating an Author instance
   author_1 = Author("George Orwell", "British")

   # Creating a Book instance using the Author instance
   book_1 = Book("1984", author_1)

   # Displaying the book information
   print(book_1.get_book_info())  # Outputs: '1984' by George Orwell, British
   ```

In this example:
- `Book` has an `Author` (composition) rather than being a type of `Author` (inheritance).
- The `Book` class uses the `Author` class's `get_details()` method to provide information about the book.

### Advantages of Composition
- **Modularity**: Each class can stand alone and be reused independently.
- **Flexibility**: You can change or replace components without affecting other parts of the system.
- **Better Abstraction**: Composition allows for more abstract relationships, focusing on what objects *have* rather than what they *are*.

### Composition vs. Inheritance

| Aspect         | Composition                          | Inheritance                         |
|----------------|-------------------------------------|-------------------------------------|
| Relationship   | "Has-a" relationship                | "Is-a" relationship                 |
| Flexibility    | More flexible; components are replaceable | Less flexible; subclasses depend on superclasses |
| Coupling       | Loosely coupled                     | More tightly coupled                |
| Example        | A `Car` has an `Engine`             | A `Dog` is an `Animal`              |

### Key Points 

- **Definition**: Composition is a way to build complex types by including objects from other classes as attributes.
- **When to Use**: Use composition when the relationship is a "has-a" rather than an "is-a."
- **Implementation**: Create an instance of another class as an attribute rather than inheriting from it.
- **Benefits**: Provides better modularity, abstraction, and flexibility than inheritance for many use cases.

Composition is a fundamental concept in OOP, helping create modular and adaptable code by linking different classes in a "has-a" relationship.
