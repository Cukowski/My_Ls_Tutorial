# My_Ls_Tutorial
 
`my_ls` is a simplified implementation of the `ls` command in C, supporting basic options like:  
- `-a` → Show hidden files  
- `-t` → Sort files by modification time  

This project is a **learning experience** focused on **systems programming**, **file handling**, and **command-line utilities**.

## 🚀 Features  
✅ List directory contents in **one-column format** (similar to `ls -1`)  
✅ **Show hidden files (`-a`)** by including entries starting with `.`  
✅ **Sort by modification time (`-t`)**, using nanosecond precision  
✅ **Handles multiple directories**, printing files before folders  
✅ **Error handling** for invalid paths and permission errors  
✅ **Memory-safe implementation**, avoiding common segmentation faults  

## 🛠️ Installation  

Clone this repository:  
```bash
git clone https://github.com/Cukowski/My_Ls_Tutorial.git
cd my_ls
```

Compile using `make`:  
```bash
make
```

If you want to clean compiled files:  
```bash
make clean
```

## 📌 Usage  

### **Basic Usage**  
Run `my_ls` to list contents of the current directory:  
```bash
./my_ls
```

### **Using Options**  
- Show hidden files:  
  ```bash
  ./my_ls -a
  ```
- Sort files by modification time (newest first):  
  ```bash
  ./my_ls -t
  ```
- Combine both options:  
  ```bash
  ./my_ls -at
  ```

### **List Specific Directories or Files**  
```bash
./my_ls dir1 dir2 file1 file2
```

## 🏗️ Project Structure  

```
📂 my_ls
├── 📂 Part1
|    ├── 📄 my_ls.c        # Main program logic
|    ├── 📄 my_ls.h        # Header file with function prototypes and structs
|    └── 📄 Makefile       # Compilation rules
├── 📂 Part2
|    ├── 📄 my_ls.c        # Main program logic
|    ├── 📄 my_ls.h        # Header file with function prototypes and structs
|    └── 📄 Makefile       # Compilation rules
└── 📄 README.md      # Documentation (this file)
```

## 🐞 Debugging  

Compile with debugging flags to detect memory issues:  
```bash
gcc -Wall -Wextra -Werror -g -fsanitize=address my_ls.c -o my_ls
```

Run the program normally:  
```bash
./my_ls -a -t
```

If you suspect a segmentation fault, use `gdb`:  
```bash
gdb ./my_ls
run -a -t
backtrace
```

## 🔧 Future Improvements  
- ✅ **Support for `-r` (reverse order)**
- ✅ **Long format listing (`-l`)**
- ✅ **Recursive directory listing (`-R`)**
- ✅ **Color support like `ls --color`**
- ✅ **More error handling improvements**

---

## 🤝 Contributing  

Feel free to submit **pull requests**, **issues**, or **feature suggestions**!  

---

## ⚖️ License  
This project is open-source and licensed under the **MIT License**.

---

Made with ❤️ by [Cukowski](https://github.com/Cukowski/)
```
