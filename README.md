# 🛡️ Terminal Utility Manager (C++ Project)

> “All-in-one terminal tool for organizing your digital life.”

A powerful, terminal-based application built in **C++** to manage:

- 🔐 Passwords
- 📇 Contacts
- 🧾 To-Do Lists
- 👤 Username Generation

This lightweight app uses **file handling** to persist data — no external databases, no UI overhead, just raw functionality with total control.

---

## 🧠 Features

### 🔐 Password Manager

- Add/view/update/delete passwords
- Saved securely in text files
- Ideal for organizing credentials offline

### 📇 Contact Book

- Store names, numbers, and emails
- Fast search and update support
- Useful for quick terminal lookup

### 🧾 To-Do List

- Add, check, or delete tasks
- Organize your daily work in CLI style

### 👤 Username Generator

- Generate usernames based on name + patterns
- Randomized options for online accounts

---

## 🛠️ Tech Stack

| Language | Libraries Used    | Data Storage |
| -------- | ----------------- | ------------ |
| C++      | iostream, fstream | .txt files   |
|          | string, cstdlib   | File system  |

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Nimit746/allapps.git
cd allapps
```

### 2. Compile the Code

Using g++:

```bash
g++ main.cpp -o utilityApp
```

### 3. Run the Program

```bash
./utilityApp
```

> Make sure your terminal has permission to read/write files in the directory.

---

## 📂 File Structure

```
cpp-terminal-utility/
├── allapps.cpp
├── Doc1.csv
├── Doc2.csv
├── Doc3.csv
├── Doc4.csv
├── master_password_hash.txt
└── README.md
```

---

## 🧪 Sample Usage

```bash
Welcome to Terminal Utility Manager

1. Manage Passwords
2. Manage Contacts
3. To-Do List
4. Username Generator
5. Exit

Enter your choice: _
```

---

## 💡 Future Enhancements

- 🔐 Encrypt stored passwords
- 🗃️ Group contacts by category
- 🧠 AI-based task suggestions
- 💾 Export/import data
