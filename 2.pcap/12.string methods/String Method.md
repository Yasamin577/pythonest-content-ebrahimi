# Strings Method

## Introduction
In Python, strings have several built-in methods that allow you to manipulate and work with text efficiently. Here are some common string methods with examples:

###Example: str.lower()
   Converts all characters to lowercase.
   
   s = "Hello World"
   print(s.lower())  # Output: "hello world"
   

###Example: str.upper()
   Converts all characters to uppercase.
   
   print(s.upper())  # Output: "HELLO WORLD"
   

###Example: str.strip()
   Removes leading and trailing whitespace.
   
   s = "  Hello World  "
   print(s.strip())  # Output: "Hello World"
   

###Example: str.replace(old, new)
   Replaces occurrences of a substring.
   
   print(s.replace("World", "Python"))  # Output: "Hello Python"
   

###Example: str.split(separator)
   Splits the string into a list based on the separator.
   
   print(s.split(" "))  # Output: ['Hello', 'World']
   
###Example: str.join(iterable)
   Joins elements of an iterable into a single string.
   
   words = ['Hello', 'World']
   print(" ".join(words))  # Output: "Hello World"
   

###Example: str.find(substring)
   Returns the index of the first occurrence of a substring.
   
   print(s.find("World"))  # Output: 6
   
