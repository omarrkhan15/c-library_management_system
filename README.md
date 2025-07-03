
# 📚 Library Management System (C++ Console App)

A simple, menu-driven Library Management System built in C++ that allows librarians and students to manage books, issue/return records, and perform key library operations via a console interface.

> Developed by **Omar Khan**

---

## 🔧 Features

- **Librarian Access (Password Protected: `omarkhan1234`)**
  - View, add, modify, delete books
  - Search books by ID or name
  - Issue and return books
  - View issued books history
  - Save/load book data

- **Student Access**
  - View available books
  - Search books

---

## 📂 File Structure

- `main.cpp` – Entry point with menus  
- `Library.h` – Main logic (class, book operations, I/O)  
- `Welcome.h` – UI headers and formatting  
- `books.txt` – Persistent book records  
- `issued_books.txt` – Issue/return logs

---

## 💻 How to Run

1. Clone the repo or copy files  
2. Compile using any C++ compiler:

```bash
g++ main.cpp -o LibraryApp
./LibraryApp
