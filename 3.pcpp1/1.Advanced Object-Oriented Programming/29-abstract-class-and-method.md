# Abstract Class And Method
In Python, an *abstract class* is a class that cannot be instantiated on its own and is meant to be inherited by other classes. Abstract classes often contain one or more *abstract methods*, which are methods declared in the abstract class but lack a concrete implementation. Subclasses are then required to provide implementations for these abstract methods. 

Abstract classes and methods provide a blueprint for other classes, enforcing a structure or contract that subclasses must follow. In Python, abstract classes and methods are created using the `abc` module, specifically the `ABC` class and `@abstractmethod` decorator.

### Key Points on Abstract Classes and Methods

- An abstract class is defined by inheriting from `ABC` (from the `abc` module).
- An abstract method is a method without implementation, marked with the `@abstractmethod` decorator.
- Any subclass of an abstract class must implement all abstract methods, or it will also be considered abstract and cannot be instantiated.

### Example: Abstract Class and Method

Consider a scenario where we want to define a general blueprint for animals with a `speak()` method. Each specific animal (e.g., Dog, Cat) will implement `speak()` differently, but we want to enforce that all animals have this method.

#### Step-by-Step Example

1. **Define the Abstract Class with Abstract Method**

   ```python
   from abc import ABC, abstractmethod

   class Animal(ABC):
       @abstractmethod
       def speak(self):
           """Abstract method that each subclass must implement"""
           pass
   ```

   Here:
   - `Animal` is an abstract class, inheriting from `ABC`.
   - The `speak()` method is an abstract method, declared using the `@abstractmethod` decorator.
   - `Animal` cannot be instantiated directly because it has at least one abstract method.

2. **Implement Subclasses**

   Each subclass of `Animal` must implement the `speak()` method. If it doesn’t, it will also be considered abstract and cannot be instantiated.

   ```python
   class Dog(Animal):
       def speak(self):
           return "Woof!"

   class Cat(Animal):
       def speak(self):
           return "Meow!"
   ```

   In this example:
   - `Dog` and `Cat` are concrete subclasses of `Animal`.
   - Each subclass provides its own implementation of `speak()`.

3. **Using the Subclasses**

   ```python
   dog = Dog()
   cat = Cat()

   print(dog.speak())  # Output: Woof!
   print(cat.speak())  # Output: Meow!
   ```

   Since `Dog` and `Cat` implement the `speak()` method, they can be instantiated and used. Attempting to instantiate `Animal` directly would raise an error:

   ```python
   animal = Animal()  # Raises TypeError: Can't instantiate abstract class Animal with abstract method speak
   ```

### Why Use Abstract Classes and Methods?

- **Enforce Consistency**: Abstract classes define a required interface, ensuring that subclasses provide specific methods.
- **Code Structure**: They help organize code, especially in larger projects, by defining a clear hierarchy.
- **Polymorphism**: By ensuring all subclasses share a common set of methods, abstract classes enable polymorphic behavior. For example, you could iterate over a list of `Animal` objects and call `speak()` on each without knowing the specific subclass.

### Real-World Example: Payment System

Imagine a payment processing system where each payment method (CreditCard, PayPal, etc.) must implement a `process_payment()` method.

```python
from abc import ABC, abstractmethod

class PaymentProcessor(ABC):
    @abstractmethod
    def process_payment(self, amount):
        pass

class CreditCardPayment(PaymentProcessor):
    def process_payment(self, amount):
        return f"Processing credit card payment of {amount}"

class PayPalPayment(PaymentProcessor):
    def process_payment(self, amount):
        return f"Processing PayPal payment of {amount}"

# Using the subclasses
payment1 = CreditCardPayment()
payment2 = PayPalPayment()

print(payment1.process_payment(100))  # Output: Processing credit card payment of 100
print(payment2.process_payment(200))  # Output: Processing PayPal payment of 200
```

In this example:
- `PaymentProcessor` is an abstract class with an abstract method `process_payment()`.
- Each subclass provides its own implementation of `process_payment()`.

### Summary Table

| Term                  | Definition                                                                 |
|-----------------------|---------------------------------------------------------------------------|
| Abstract Class        | A class that cannot be instantiated and often has abstract methods.       |
| Abstract Method       | A method declared in an abstract class that must be implemented by subclasses. |
| Purpose               | Enforces that all subclasses adhere to a specified interface.             |
| Example Use Case      | Payment processing classes, where each payment method must implement `process_payment()`. |

### Key Points 

- **Abstract Classes and `ABC`**: Know how to define an abstract class using `ABC`.
- **`@abstractmethod` Decorator**: Understand how to declare abstract methods that subclasses must implement.
- **Polymorphism and Flexibility**: Abstract classes are key to enforcing structure and enabling polymorphic behavior in OOP.

Abstract classes and methods help you define a blueprint that ensures consistent implementation across subclasses, promoting both flexibility and structure in Python applications.
