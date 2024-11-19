# Operation On String

In Python, string operations include various methods and functionalities that allow you to manipulate and interact with strings. Here are some common operations on strings along with examples:

### 1. Concatenation
Combining two or more strings using the `+` operator.

```python
str1 = "Hello"
str2 = "World"
result = str1 + " " + str2  # 'Hello World'
print(result)
```

### 2. Repetition
Repeating a string multiple times using the `*` operator.

```python
str3 = "Hi! "
result = str3 * 3  # 'Hi! Hi! Hi! '
print(result)
```

### 3. Slicing
Extracting a substring from a string using indexing.

```python
str4 = "Python Programming"
substring = str4[0:6]  # 'Python'
print(substring)
```

### 4. Length
Finding the length of a string using the `len()` function.

```python
str5 = "Hello, World!"
length = len(str5)  # 13
print(length)
```

### 5. String Methods
Using built-in string methods for various operations.

- **Uppercase and Lowercase:**

```python
str6 = "hello"
upper_str = str6.upper()  # 'HELLO'
lower_str = upper_str.lower()  # 'hello'
print(upper_str, lower_str)
```

- **Finding a Substring:**

```python
str7 = "Hello, World!"
index = str7.find("World")  # 7
print(index)
```

- **Replacing Substrings:**

```python
str8 = "I like apples"
new_str = str8.replace("apples", "bananas")  # 'I like bananas'
print(new_str)
```

- **Splitting a String:**

```python
str9 = "apple,banana,cherry"
fruits = str9.split(",")  # ['apple', 'banana', 'cherry']
print(fruits)
```

### 6. Checking String Properties
Using methods to check the characteristics of a string.

- **Is Digit:**

```python
str10 = "12345"
is_digit = str10.isdigit()  # True
print(is_digit)
```

- **Is Alpha:**

```python
str11 = "Hello"
is_alpha = str11.isalpha()  # True
print(is_alpha)
```

### Example of Multiple String Operations

Here’s a complete example demonstrating various string operations:

```python
# Initial string
text = "  Python Programming  "

# 1. Strip whitespace
stripped_text = text.strip()  # 'Python Programming'
print("Stripped:", stripped_text)

# 2. Convert to uppercase
upper_text = stripped_text.upper()  # 'PYTHON PROGRAMMING'
print("Uppercase:", upper_text)

# 3. Find a substring
position = upper_text.find("PROGRAMMING")  # 7
print("Position of 'PROGRAMMING':", position)

# 4. Replace a word
replaced_text = upper_text.replace("PYTHON", "JAVA")  # 'JAVA PROGRAMMING'
print("Replaced:", replaced_text)

# 5. Split into words
words = replaced_text.split()  # ['JAVA', 'PROGRAMMING']
print("Words:", words)

# 6. Join words back into a string
joined_text = " ".join(words)  # 'JAVA PROGRAMMING'
print("Joined:", joined_text)
```

### Summary
String operations in Python are powerful and versatile, allowing for a wide range of manipulations and checks. Understanding these operations is essential for effective string handling in Python programming.
