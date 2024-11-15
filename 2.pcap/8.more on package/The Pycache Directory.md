# The `__pycache__` Directory in Python

## **What is `__pycache__`?**

- The `__pycache__` directory is automatically created by Python when a module is imported.
- It stores **compiled bytecode files** (with a `.pyc` extension) for your Python scripts.
- These `.pyc` files make subsequent execution faster by skipping the compilation step.

### **Why `__pycache__` Exists?**

- Python compiles `.py` files into bytecode before running them.
- Bytecode is platform-independent and optimized for faster execution.
- If the source code doesn’t change, Python uses the bytecode from `__pycache__`.

---

### **Example**

1. Create a Python file named `example.py`:

   ```python
   def greet():
       print("Hello from example.py!")
   ```

2. Run the script:

   ```bash
   python example.py
   ```

3. Import the file in another script:

   ```python
   # Create a file `main.py`
   import example
   example.greet()
   ```

4. After importing or running `example.py`, a `__pycache__` directory is created in the same location as `example.py`.

---

### **What You’ll See**

The `__pycache__` directory contains:

```

__pycache__/
    example.cpython-<version>.pyc
```

- `example.cpython-<version>.pyc`: A compiled bytecode version of `example.py`. The `<version>` corresponds to your Python version (e.g., `cpython-310` for Python 3.10).

---

### **How `__pycache__` Works**

1. If the file hasn’t changed, Python uses the `.pyc` file instead of recompiling.
2. If you modify the source file (`example.py`), Python automatically recompiles it and updates the `.pyc` file.

---

### **Disabling `__pycache__`**

You can disable `__pycache__` creation by running Python with the `-B` flag:

```bash
python -B example.py
```
