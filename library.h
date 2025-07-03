#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <limits>
#include <string>

struct Books {
    int bookID;
    std::string bookName;
    std::string authorName;
    int quantity;
};

class Library {
private:
    std::vector<Books> books;
    int bookCount = 0;
    const std::string librarianPassword = "omarkhan1234";

    void displayBookDetails(const Books& book, int x) const;
    bool isBookAlreadyIssued(int studentID);

public:
    void MainMenu(Library& byteCode);
    void LibrarianMenu(Library& librarian);
    void StudentMenu(Library& student);

    void addBook();
    void modifyBook();
    void deleteBook();
    void viewBookList(int x = 1) const;
    void searchBook(int x);
    void issueBookToStudent();
    void returnBookFromStudent();
    void viewIssuedBooksHistory();
    void saveBookData();
    void loadBookData();

    static void headMessage(const std::string& message);
    static void pause();
    static void clearScreen();
};

#endif
