# Overriding Abstract Methods
**Overriding abstract methods** in Python involves implementing methods that are defined in an abstract base class (ABC) but lack implementation details. When a subclass inherits from an abstract base class, it is required to override and implement all abstract methods, or it cannot be instantiated. This is a powerful OOP concept for enforcing that subclasses implement certain behavior, allowing the superclass to act as a blueprint.

### Key Points of Abstract Base Classes (ABCs) and Abstract Methods

1. **Abstract Base Class**: An abstract base class serves as a template, containing one or more abstract methods that subclasses must implement.
2. **Abstract Methods**: These are methods defined in an abstract base class with no implementation. They are decorated with `@abstractmethod`.
3. **Implementation Requirement**: Any class inheriting from an abstract base class must implement all abstract methods. If it does not, it, too, becomes abstract and cannot be instantiated.

### Using `abc` Module to Define Abstract Base Classes and Methods

To create an abstract base class in Python, we use the `abc` module:
1. Import `ABC` and `abstractmethod` from the `abc` module.
2. Define an abstract base class that inherits from `ABC`.
3. Use the `@abstractmethod` decorator to define abstract methods.

### Example: Overriding Abstract Methods

Let's create an abstract base class `Vehicle` with two abstract methods, `start_engine()` and `stop_engine()`, and implement these methods in subclasses `Car` and `Motorcycle`.

1. **Defining the Abstract Base Class**

   ```python
   from abc import ABC, abstractmethod

   class Vehicle(ABC):
       @abstractmethod
       def start_engine(self):
           """Start the engine of the vehicle."""
           pass

       @abstractmethod
       def stop_engine(self):
           """Stop the engine of the vehicle."""
           pass
   ```

   Here, `Vehicle` is an abstract base class with two abstract methods:
   - `start_engine()`: To be implemented in subclasses.
   - `stop_engine()`: Also to be implemented in subclasses.

2. **Implementing Subclasses and Overriding Abstract Methods**

   Now, we create two subclasses, `Car` and `Motorcycle`, each providing its own implementation of the `start_engine()` and `stop_engine()` methods.

   ```python
   class Car(Vehicle):
       def start_engine(self):
           return "Car engine started."

       def stop_engine(self):
           return "Car engine stopped."

   class Motorcycle(Vehicle):
       def start_engine(self):
           return "Motorcycle engine started."

       def stop_engine(self):
           return "Motorcycle engine stopped."
   ```

   In this example:
   - `Car` and `Motorcycle` both inherit from `Vehicle`.
   - Each subclass provides its own implementation of `start_engine()` and `stop_engine()`, overriding the abstract methods from the `Vehicle` class.

3. **Using the Subclasses**

   Since `Car` and `Motorcycle` have implemented all abstract methods, they can now be instantiated, and their methods can be called.

   ```python
   # Create instances of Car and Motorcycle
   my_car = Car()
   my_motorcycle = Motorcycle()

   print(my_car.start_engine())       # Outputs: Car engine started.
   print(my_motorcycle.start_engine()) # Outputs: Motorcycle engine started.
   print(my_car.stop_engine())        # Outputs: Car engine stopped.
   print(my_motorcycle.stop_engine()) # Outputs: Motorcycle engine stopped.
   ```

   Here, each instance behaves according to its own `start_engine()` and `stop_engine()` implementations, even though both share the same abstract interface defined by `Vehicle`.

### Practical Use Cases of Overriding Abstract Methods

1. **Enforcing Consistency**: Abstract methods ensure that subclasses provide specific methods, which is useful in large applications to maintain consistent interfaces.
2. **Template for Extension**: Abstract classes provide a template for future subclasses, ensuring essential functionality without restricting how it’s implemented.
3. **Polymorphism**: Abstract methods support polymorphism, allowing you to use objects of different classes interchangeably as long as they implement the same methods.

### Key Points 

- **Abstract Base Classes (ABCs)**: Understand that abstract classes cannot be instantiated and are designed for inheritance.
- **Abstract Methods**: Subclasses inheriting from an abstract base class must implement all abstract methods to be instantiated.
- **Using `abc` Module**: Be familiar with the `ABC` class and `@abstractmethod` decorator for defining abstract classes and methods.
- **Polymorphism**: Abstract methods enforce a common interface, enabling polymorphism.

Overriding abstract methods allows for structured, enforceable designs where certain methods are required across subclasses, but each subclass can implement them in its own way. This is key to creating flexible, extendable, and maintainable Python code.