# Deleter Method
In Python, a *deleter method* is a special type of method used to delete an attribute of an instance. It’s part of the property decorator mechanism, where we define getter, setter, and deleter methods to control access to an attribute. The `@property` decorator allows us to manage attributes in a class, and the `@<property>.deleter` decorator allows you to define custom behavior for deleting an attribute.

### Why Use a Deleter Method?

A deleter method provides a controlled way to delete an attribute. It’s particularly useful if you need to perform additional actions when an attribute is deleted, like logging, clearing related attributes, or ensuring that deleting the attribute doesn’t cause unintended issues.

### Defining a Deleter Method

To create a deleter method, define a property using `@property`, then define a deleter using the `@<property>.deleter` decorator.

### Example: Using a Deleter Method

Consider a class that represents a `Person` with a `full_name` attribute. We want to define custom behavior for setting, getting, and deleting `full_name`.

```python
class Person:
    def __init__(self, first_name, last_name):
        self._first_name = first_name
        self._last_name = last_name

    # Getter for full_name
    @property
    def full_name(self):
        return f"{self._first_name} {self._last_name}"

    # Setter for full_name
    @full_name.setter
    def full_name(self, name):
        first, last = name.split(" ")
        self._first_name = first
        self._last_name = last

    # Deleter for full_name
    @full_name.deleter
    def full_name(self):
        print("Deleting full_name...")
        self._first_name = None
        self._last_name = None

# Using the deleter method
person = Person("John", "Doe")
print(person.full_name)  # Output: John Doe

# Delete the full_name attribute
del person.full_name
print(person.full_name)  # Output: None None
```

#### Explanation of the Example

1. **Getter**: The `@property` decorator defines the `full_name` property, which returns the `first_name` and `last_name` attributes.
2. **Setter**: The `@full_name.setter` decorator allows us to set `full_name` by splitting a single string into `first_name` and `last_name`.
3. **Deleter**: The `@full_name.deleter` decorator defines custom behavior when `full_name` is deleted. In this case, it sets both `first_name` and `last_name` to `None` and prints a message.

When `del person.full_name` is called:
- The `full_name` deleter is triggered.
- The `first_name` and `last_name` attributes are set to `None`.

#### Output
```
John Doe
Deleting full_name...
None None
```

### Key Points 

- **Purpose of a Deleter**: The deleter method allows custom behavior when deleting an attribute.
- **Property Decorators**: Understand the role of `@property`, `@<property>.setter`, and `@<property>.deleter`.
- **Controlled Deletion**: A deleter method provides a controlled way to delete an attribute, which is useful for managing class state.

Deleter methods provide a useful way to handle the deletion of attributes in a controlled manner, which can be essential for maintaining data integrity in complex applications.