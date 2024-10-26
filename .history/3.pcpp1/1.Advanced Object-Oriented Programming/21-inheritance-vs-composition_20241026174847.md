# Inheritance Vs Composition
In Python, *inheritance* and *composition* are two fundamental design patterns for creating relationships between classes. Both enable code reuse, but they achieve it in different ways. 

- **Inheritance** creates an "is-a" relationship, where a child class inherits properties and behaviors from a parent class.
- **Composition** creates a "has-a" relationship, where one class contains an instance of another class, meaning it *has* certain functionality rather than *is* a type of it.

Choosing between inheritance and composition depends on the structure and flexibility required in your code.

---

### Inheritance

*Inheritance* allows a new class (subclass) to inherit attributes and methods from an existing class (superclass). This is useful for creating specialized versions of a general class.

#### Example: Inheritance (is-a Relationship)

Let's say we have a general class `Animal`, and we want to create a specialized class `Dog` that inherits from `Animal`.

```python
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        return "Some sound"

class Dog(Animal):  # Dog inherits from Animal
    def speak(self):
        return f"{self.name} says Woof!"

# Creating an instance of Dog
dog = Dog("Buddy")
print(dog.speak())
```

#### Output
```
Buddy says Woof!
```

- Here, `Dog` inherits from `Animal`, meaning it "is an" animal with the additional specific behavior of saying "Woof!"

---

### Composition

*Composition*, on the other hand, involves building classes by combining them. Rather than inheriting behavior, composition embeds objects from one class inside another. This is often useful for making classes more modular and reusable.

#### Example: Composition (has-a Relationship)

Now, let's use composition to create a `Dog` class that has a `Legs` class as part of its structure. Instead of saying a `Dog` "is an" animal, we’re saying a `Dog` "has" legs.

```python
class Legs:
    def __init__(self, number_of_legs):
        self.number_of_legs = number_of_legs

class Dog:
    def __init__(self, name):
        self.name = name
        self.legs = Legs(4)  # Composition: Dog has Legs

    def speak(self):
        return f"{self.name} says Woof and has {self.legs.number_of_legs} legs."

# Creating an instance of Dog
dog = Dog("Buddy")
print(dog.speak())
```

#### Output
```
Buddy says Woof and has 4 legs.
```

- In this case, `Dog` has a `Legs` object as an attribute, creating a "has-a" relationship.

---

### Inheritance vs Composition: Key Differences

| Aspect               | Inheritance                                         | Composition                                    |
|----------------------|-----------------------------------------------------|------------------------------------------------|
| Relationship         | *Is-a* relationship (e.g., `Dog` is an `Animal`)    | *Has-a* relationship (e.g., `Dog` has `Legs`)  |
| Code Reuse           | Achieved through inherited methods/attributes       | Achieved by using instances of other classes   |
| Flexibility          | Less flexible, tightly couples child to parent      | More flexible, allows modularity and reuse     |
| Example              | `class Dog(Animal):`                                | `class Dog: self.legs = Legs()`                |
| When to Use          | When there's a clear "is-a" relationship            | When the relationship is more "has-a"          |

---

### When to Use Inheritance vs Composition

- **Use Inheritance** when:
  - There is a clear "is-a" relationship.
  - You want the child class to inherit all behaviors and attributes of the parent class.
  - You need to extend or customize behavior in the child class.

- **Use Composition** when:
  - The relationship is "has-a" rather than "is-a."
  - You want to combine behavior from multiple classes without tightly coupling them.
  - You want flexibility in changing or swapping components without altering the main class.

### Practical Example of Both

Imagine a `Car` class that "has" an `Engine` and "is a" type of `Vehicle`.

```python
class Engine:
    def start(self):
        return "Engine starts."

class Vehicle:
    def move(self):
        return "Vehicle moves."

class Car(Vehicle):  # Inheritance: Car is a type of Vehicle
    def __init__(self):
        self.engine = Engine()  # Composition: Car has an Engine

    def drive(self):
        engine_status = self.engine.start()  # Using composition
        movement = self.move()  # Using inheritance
        return f"{engine_status} and {movement}"

# Creating an instance of Car
my_car = Car()
print(my_car.drive())
```

#### Output
```
Engine starts. and Vehicle moves.
```

In this example:
- **Inheritance** is used because `Car` "is a" `Vehicle`.
- **Composition** is used because `Car` "has an" `Engine`.

This design allows for flexibility: if you need a different engine type, you can replace the `Engine` class without modifying the `Car` class directly.

---

### Key Points 

- **Understand Relationships**: Choose inheritance for "is-a" and composition for "has-a" relationships.
- **Flexibility and Modularity**: Composition is generally more flexible, making it ideal for scenarios where components might change.
- **Examples of Each**: Be prepared to identify and implement both inheritance and composition.

Both inheritance and composition are essential for designing maintainable and reusable code. While inheritance creates a hierarchy, composition allows for flexible, modular design that can adapt to changes easily.