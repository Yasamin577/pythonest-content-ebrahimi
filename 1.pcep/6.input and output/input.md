# Input

In Python, the **`input()`** function is used to capture user input from the keyboard. It reads the input as a string by default, and you can then process or convert it as needed (e.g., to an integer or float).

## Syntax

```python
input(prompt)
```

- **`prompt`**: A string that is displayed to the user, asking for input (optional).

## Example

```python
# Prompt the user for their name and age
name = input("Enter your name: ")
age = input("Enter your age: ")

# Display the entered information
print("Hello, " + name + "! You are " + age + " years old.")
```

### Explanation

1. **`input("Enter your name: ")`**: Displays the prompt "Enter your name:" and waits for the user to input a string, which is stored in the variable `name`.
2. **`input("Enter your age: ")`**: Similarly, prompts the user for their age, which is also stored as a string.
3. **`print()`**: Outputs a message using the collected input.

## Converting Input to Other Data Types

Since `input()` returns a string, you may need to convert the input to other types (like integers or floats) using functions like `int()` or `float()`.

```python
# Input a number and convert it to an integer
number = input("Enter a number: ")
number = int(number)  # Convert to integer

# Perform operations
print("Double of your number is:", number * 2)
```
