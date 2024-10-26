# Attribute Encapsulation
**Attribute encapsulation** in Python is a fundamental concept in Object-Oriented Programming (OOP) that controls access to an object's attributes (data) to prevent unintended interference or modification. Encapsulation achieves this by restricting access to attributes and methods, often through private and protected variables, ensuring data integrity and hiding implementation details from outside access.

### Key Concepts of Attribute Encapsulation

1. **Public Attributes**: Accessible from anywhere in the code. In Python, variables that don’t have an underscore prefix are considered public.
2. **Protected Attributes**: Accessible within the class and its subclasses, but not from outside. In Python, these are denoted with a single underscore (`_attribute`).
3. **Private Attributes**: Accessible only within the class, providing the highest level of encapsulation. These attributes use a double underscore prefix (`__attribute`).

### Example of Attribute Encapsulation in Python

Let’s create a `BankAccount` class to illustrate the different levels of attribute encapsulation.

1. **Define the `BankAccount` Class**

   ```python
   class BankAccount:
       def __init__(self, owner, balance):
           self.owner = owner              # Public attribute
           self._account_number = "12345"  # Protected attribute
           self.__balance = balance        # Private attribute

       def deposit(self, amount):
           if amount > 0:
               self.__balance += amount
               print(f"Deposited {amount}. New balance: {self.__balance}")

       def __update_balance(self, amount):  # Private method
           self.__balance += amount

       def get_balance(self):
           return self.__balance
   ```

   - `self.owner` is a public attribute that can be accessed directly outside the class.
   - `self._account_number` is a protected attribute, suggesting that it should not be accessed outside the class or subclasses.
   - `self.__balance` is a private attribute, only accessible within the class.
   - `__update_balance` is a private method, meant to be used only inside the class.

2. **Accessing Attributes Outside the Class**

   ```python
   account = BankAccount("Alice", 1000)

   # Accessing public attribute
   print(account.owner)              # Outputs: Alice

   # Accessing protected attribute
   print(account._account_number)    # Outputs: 12345 (but not recommended)

   # Accessing private attribute (will raise an error if accessed directly)
   # print(account.__balance)         # Raises AttributeError

   # Access private attribute using a public method
   print(account.get_balance())      # Outputs: 1000
   ```

   Here:
   - The `owner` attribute is accessed directly, as it’s public.
   - The `_account_number` attribute can be accessed but should be treated with caution outside the class, as it’s intended for internal use.
   - The `__balance` attribute is private, and attempting to access it directly raises an `AttributeError`.

3. **Using Name Mangling to Access Private Attributes (Not Recommended)**

   In Python, private attributes are "name-mangled," meaning they are stored with a name like `_ClassName__attribute`. This makes them harder to access from outside but not impossible.

   ```python
   # Accessing private attribute using name mangling (not recommended)
   print(account._BankAccount__balance)  # Outputs: 1000
   ```

   This approach circumvents encapsulation, which can lead to issues and is generally discouraged.

### Why Use Attribute Encapsulation?

- **Data Protection**: Protects attributes from unintended modification or misuse outside the class.
- **Encapsulation of Internal Details**: Encapsulation hides the internal workings of a class, allowing you to change the implementation without affecting outside code.
- **Controlled Access**: You can control how attributes are accessed and modified through public methods, like `get_balance()` and `deposit()`, which makes code safer and more maintainable.

### Practical Use Cases for Attribute Encapsulation

- **Banking and Financial Applications**: Encapsulation is essential for protecting sensitive data, like account balances and transaction histories, from unauthorized access.
- **Large Codebases**: Encapsulation reduces complexity by hiding details and ensuring that only intended components are accessible.
- **Access Control**: Through encapsulation, classes can expose only the necessary interfaces (e.g., public methods), keeping other data hidden.

### Key Points 

- **Access Levels**: Understand the difference between public, protected, and private attributes and how they control access.
- **Encapsulation Benefits**: Familiarize yourself with why encapsulation is used, including data protection, controlled access, and hiding implementation details.
- **Name Mangling**: Recognize that name mangling adds a level of privacy to private attributes, but should generally not be used for direct access.

Attribute encapsulation is a fundamental aspect of writing secure and robust OOP code, ensuring that data within objects is accessible and modifiable only in controlled ways.