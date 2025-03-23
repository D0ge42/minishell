# Minishell - 42 Project (125/100) (Made together with [Eutrius](https://github.com/Eutrius))

Minishell is a **fully functional and robust UNIX shell**, developed as part of the **42 School** curriculum. This project replicates the behavior of a real shell while deep-diving into complex C concepts such as **binary trees, enums, function pointers, bitwise operations, recursion, and more**. With a **debug mode** to visualize the execution tree and a **bulletproof implementation** free from memory leaks and segmentation faults, this Minishell is as solid as it gets. 🚀

## 🌟 Features
- **Command execution** (including built-in and external commands)
- **Binary tree-based parser** for structured command execution
- **Signal handling** (`CTRL+C`, `CTRL+D`, `CTRL+Z` support)
- **Recursive execution** for complex command structures
- **Bitwise operations** for efficient flag management
- **Function pointers** for dynamic command handling
- **Full support for pipes (`|`), redirections (`>`, `>>`, `<`), and heredoc (`<<`)**
- **Environment variable expansion (`$VAR`)**
- **Wildcards (`*`) support** for flexible file matching
- **Debug mode** to visualize the execution tree
- **Support for logical operators (`&&`, `||`) and parentheses for grouping commands**
- **Bulletproof stability** (no memory leaks, no segmentation faults)
- **Fully completed with bonuses (125/100 score!)**

## 🛠️ Compilation & Usage
### 🔧 Build
```bash
make
```

### 🚀 Run Minishell
```bash
./minishell
```

### 💧 Check Leaks
```bash
make valgrind
```

### 🔍 Debug Mode
To visualize the execution tree:
```
Type debug while inside minishell.
Type debug again to exit debugging mode.
```

## 📌 Built-in Commands
- `cd`  - Change directory
- `pwd` - Print working directory
- `echo` - Print output
- `export` - Set environment variables
- `unset` - Remove environment variables
- `env` - Display environment variables
- `exit` - Exit the shell

## 📖 How It Works
1. **Lexing & Parsing** - The input is tokenized and structured into a **binary tree**.
2. **Execution Tree** - Commands are executed based on their tree structure.
3. **Redirections & Pipes** - Proper file descriptor management ensures smooth execution.
4. **Logical Operators & Parentheses** - Commands can be grouped using `()` and executed conditionally with `&&` and `||`.
5. **Signal Handling** - Interruptions are properly managed.
6. **Memory Management** - Every allocation is tracked, ensuring **zero memory leaks**.

## 📷 Debug Mode Example (Execution Tree)
```
      [PIPE]
      /    \
   [CMD]  [CMD]
  /      \
ls       wc -l
```

## 🏆 Why This Minishell?
✅ **Complete implementation with bonuses** (125/100 score)  
✅ **Memory-leak-free & crash-proof**  
✅ **Optimized with recursion, enums, and bitwise operations**  
✅ **Debug mode for easy visualization**  
✅ **Supports complex shell behaviors including logical operators and parentheses**  

## 📝 License 
This project is open-source and free to use for educational purposes.

---
Welcome to your new favorite shell! 🐚🚀

