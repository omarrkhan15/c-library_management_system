#include "Library.h"
#include "Welcome.h"
#include <iomanip>
#include <limits>

void Library::headMessage(const std::string& message) {
    ::headMessage(message.c_str());
}

void Library::pause() {
    std::cout << "\nPress enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void Library::clearScreen() {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void Library::MainMenu(Library& byteCode) {
    int choice;
    do {
        clearScreen();
        headMessage("Library Management System");
        std::cout << "\n\n\t\t\t1. Librarian Menu";
        std::cout << "\n\n\t\t\t2. Student Menu";
        std::cout << "\n\n\t\t\t0. Exit";
        std::cout << "\n\n\t\t\tEnter your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\t\t\tInvalid input! Please enter a number.";
            pause();
            continue;
        }

        switch (choice) {
            case 1: {
                std::string passCode;
                clearScreen();
                headMessage("Librarian Authentication");
                std::cout << "\n\n\t\t\tPlease enter password for librarian: ";
                std::cin >> passCode;

                if (passCode == librarianPassword) {
                    std::cout << "\n\n\t\t\tAccess Granted! Welcome to the Library.";
                    pause();
                    LibrarianMenu(byteCode);
                } else {
                    std::cout << "\n\n\t\t\tAccess Denied! Incorrect password.";
                    pause();
                }
                break;
            }
            case 2:
                StudentMenu(byteCode);
                break;
            case 0:
                exit(0);
            default:
                std::cout << "\n\t\t\tInvalid choice! Please try again.";
                pause();
        }
    } while (true);
}

void Library::LibrarianMenu(Library& librarian) {
    int librarianChoice;
    do {
        clearScreen();
        headMessage("Librarian Menu");

        std::cout << "\n\n\t\t\t1. View Book List";
        std::cout << "\n\n\t\t\t2. Search Book";
        std::cout << "\n\n\t\t\t3. Add Book";
        std::cout << "\n\n\t\t\t4. Modify Book";
        std::cout << "\n\n\t\t\t5. Delete Book";
        std::cout << "\n\n\t\t\t6. Issue Book";
        std::cout << "\n\n\t\t\t7. Return Book";
        std::cout << "\n\n\t\t\t8. View Issued Books History";
        std::cout << "\n\n\t\t\t9. Save Book Data";
        std::cout << "\n\n\t\t\t10. Main Menu";
        std::cout << "\n\n\t\t\t0. Exit";
        std::cout << "\n\n\t\t\tEnter your choice: ";

        if (!(std::cin >> librarianChoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\t\t\tInvalid input! Please enter a number.";
            pause();
            continue;
        }

        switch (librarianChoice) {
            case 1: librarian.viewBookList(); break;
            case 2: librarian.searchBook(1); break;
            case 3: librarian.addBook(); break;
            case 4: librarian.modifyBook(); break;
            case 5: librarian.deleteBook(); break;
            case 6: librarian.issueBookToStudent(); break;
            case 7: librarian.returnBookFromStudent(); break;
            case 8: viewIssuedBooksHistory(); break;
            case 9: librarian.saveBookData(); break;
            case 10: return;
            case 0: exit(0);
            default:
                std::cout << "\n\t\t\tInvalid choice! Please try again.";
                pause();
        }
    } while (true);
}

void Library::StudentMenu(Library& student) {
    int studentChoice;
    do {
        clearScreen();
        headMessage("Student Menu");
        std::cout << "\n\n\t\t\t1. View Book List";
        std::cout << "\n\n\t\t\t2. Search Book";
        std::cout << "\n\n\t\t\t0. Go Back";
        std::cout << "\n\n\t\t\tEnter your choice: ";

        if (!(std::cin >> studentChoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\n\t\t\tInvalid input! Please enter a number.";
            pause();
            continue;
        }

        switch (studentChoice) {
            case 1:
                student.viewBookList(2);
                break;
            case 2:
                student.searchBook(2);
                break;
            case 0:
                return;
            default:
                std::cout << "\n\t\t\tInvalid choice! Please try again.";
                pause();
        }
    } while (true);
}

void Library::addBook() {
    headMessage("Add Book");
    Books newBook;

    std::cout << "\n\n\t\t\tEnter Book ID: ";
    std::cin >> newBook.bookID;
    std::cin.ignore();

    for (const auto& book : books) {
        if (book.bookID == newBook.bookID) {
            std::cout << "\n\t\t\tBook with the same ID already exists.";
            pause();
            return;
        }
    }

    std::cout << "\n\t\t\tEnter Book Name: ";
    std::getline(std::cin, newBook.bookName);

    std::cout << "\n\t\t\tEnter Author Name: ";
    std::getline(std::cin, newBook.authorName);

    std::cout << "\n\t\t\tEnter Quantity: ";
    std::cin >> newBook.quantity;

    books.push_back(newBook);
    bookCount++;

    std::cout << "\n\t\t\tBook added successfully";
    pause();
}

void Library::modifyBook() {
    headMessage("Modify Book");
    std::cout << "\n\n";

    int id;
    std::cout << "\n\t\t\tEnter Book ID to modify: ";
    std::cin >> id;

    bool found = false;
    for (auto& book : books) {
        if (book.bookID == id) {
            std::cout << "\n\t\t\tEnter new Book Name: ";
            std::cin.ignore();
            std::getline(std::cin, book.bookName);

            std::cout << "\n\t\t\tEnter new Author Name: ";
            std::getline(std::cin, book.authorName);

            std::cout << "\n\t\t\tEnter new Quantity: ";
            std::cin >> book.quantity;

            std::cout << "\n\t\t\tBook modified successfully!";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "\n\t\t\tBook not found!";
    }
    pause();
}

void Library::deleteBook() {
    headMessage("Delete Book");
    std::cout << "\n\n";
    int id;
    std::cout << "\n\t\t\tEnter Book ID to delete: ";
    std::cin >> id;

    auto it = std::find_if(books.begin(), books.end(), [id](const Books& b) { return b.bookID == id; });

    if (it != books.end()) {
        books.erase(it);
        bookCount--;
        std::cout << "\n\t\t\tBook deleted successfully!";
    } else {
        std::cout << "\n\t\t\tBook not found!";
    }
    pause();
}

void Library::viewBookList(int x) const {
    headMessage("View Book List");
    std::cout << "\n\n";
    if (books.empty()) {
        std::cout << "\n\n\t\t\tNo books found!";
    } else {
        int i = 1;
        for (const auto& book : books) {
            std::cout << "\n\n\t\t\t\t\t\t********** " << i++ << ". ********** \n";
            std::cout << "\n\t\t\tBook Name : " << book.bookName << "\n";
            std::cout << "\n\t\t\tBook's Author Name : " << book.authorName << "\n";
            std::cout << "\n\t\t\tBook's ID : " << book.bookID << "\n";
            if (x == 1) {
                std::cout << "\n\t\t\tBook's Quantity : " << book.quantity << "\n";
            }
        }
    }
    pause();
}

void Library::searchBook(int x) {
    headMessage("Search Book");
    int choice;

    std::cout << "\n\n\t\t\t1. Search by Book ID";
    std::cout << "\n\n\t\t\t2. Search by Book Name";
    std::cout << "\n\n\t\t\tEnter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    clearScreen();

    switch (choice) {
        case 1: {
            int bookID;
            std::cout << "\n\n\t\t\tEnter Book ID: ";
            std::cin >> bookID;
            std::cin.ignore();

            for (const auto& book : books) {
                if (book.bookID == bookID) {
                    std::cout << "\n\n\t\t\tBook Found!";
                    displayBookDetails(book, x);
                    return;
                }
            }
            std::cout << "\n\n\t\t\tBook not found!";
            break;
        }
        case 2: {
            std::string bookName;
            std::cout << "\n\n\t\t\tEnter Book Name: ";
            std::getline(std::cin, bookName);

            for (const auto& book : books) {
                if (book.bookName == bookName) {
                    std::cout << "\n\n\t\t\tBook Found!";
                    displayBookDetails(book, x);
                    return;
                }
            }
            std::cout << "\n\n\t\t\tBook not found!";
            break;
        }
        default:
            std::cout << "\n\n\t\t\tInvalid choice! Please try again.";
    }
    pause();
}

void Library::displayBookDetails(const Books& book, int x) const {
    headMessage("Book Details");
    std::cout << "\n\n\t\t\tBook ID: " << book.bookID;
    std::cout << "\n\n\t\t\tBook Name: " << book.bookName;
    std::cout << "\n\n\t\t\tAuthor Name: " << book.authorName;
    if (x == 1) {
        std::cout << "\n\n\t\t\tQuantity: " << book.quantity;
    }
    pause();
}

bool Library::isBookAlreadyIssued(int studentID) {
    std::ifstream file("issued_books.txt");
    if (!file.is_open()) {
        return false;
    }

    int id, book;
    while (file >> id >> book) {
        if (id == studentID) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void Library::issueBookToStudent() {
    headMessage("Issue Book to Student");

    int studentID, bookID;
    std::cout << "\n\t\t\tEnter Student ID: ";
    std::cin >> studentID;
    std::cin.ignore();

    std::cout << "\n\t\t\tEnter Book ID: ";
    std::cin >> bookID;
    std::cin.ignore();

    auto it = std::find_if(books.begin(), books.end(), [bookID](const Books& b) { return b.bookID == bookID; });

    if (it == books.end()) {
        std::cout << "\n\t\t\tBook not found in the library!\n";
        pause();
        return;
    }
    Books& book = *it;
    if (isBookAlreadyIssued(studentID)) {
        std::cout << "\n\t\t\tStudent already has a book issued!\n";
        pause();
        return;
    }
    if (book.quantity <= 0) {
        std::cout << "\n\t\t\tNo stock available for this book!\n";
        pause();
        return;
    }
    book.quantity--;
    std::ofstream outFile("issued_books.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << studentID << " " << bookID << " " << std::time(nullptr) << "\n";
        outFile.close();
        std::cout << "\n\t\t\tBook '" << book.bookName << "' issued successfully!\n";
        saveBookData();
    } else {
        std::cout << "\n\t\t\tFailed to issue book!\n";
    }
    pause();
}

void Library::returnBookFromStudent() {
    headMessage("Return Book from Student");
    int studentID, bookID;
    std::cout << "\n\t\t\tEnter Student ID: ";
    std::cin >> studentID;
    std::cin.ignore();

    std::cout << "\n\t\t\tEnter Book ID: ";
    std::cin >> bookID;
    std::cin.ignore();

    bool bookIssued = false;
    std::ifstream file("issued_books.txt");
    if (file.is_open()) {
        int id, book;
        while (file >> id >> book) {
            if (id == studentID && book == bookID) {
                bookIssued = true;
                break;
            }
        }
        file.close();
    }
    if (bookIssued) {
        std::time_t currentTime = std::time(nullptr);
        std::ifstream bookRecords("issued_books.txt");
        if (bookRecords.is_open()) {
            int id, book;
            while (bookRecords >> id >> book) {
                if (id == studentID && book == bookID) {
                    std::time_t issueTime;
                    bookRecords >> issueTime;
                    double days = std::difftime(currentTime, issueTime) / (24 * 60 * 60);
                    if (days > 30) {
                        double fine = 15 * (days - 30);
                        std::cout << "\n\t\t\tFine to be paid: $" << std::fixed << std::setprecision(2) << fine << "\n";
                        pause();
                    }
                    break;
                }
            }
            bookRecords.close();
        }
        std::ifstream inputFile("issued_books.txt");
        std::ofstream outputFile("temp.txt");
        if (inputFile.is_open() && outputFile.is_open()) {
            int id, book;
            std::time_t issueTime;
            while (inputFile >> id >> book >> issueTime) {
                if (!(id == studentID && book == bookID)) {
                    outputFile << id << " " << book << " " << issueTime << "\n";
                }
            }
            inputFile.close();
            outputFile.close();
            std::remove("issued_books.txt");
            std::rename("temp.txt", "issued_books.txt");
            for (auto& b : books) {
                if (b.bookID == bookID) {
                    b.quantity += 1;
                    saveBookData();
                    std::cout << "\n\t\t\tBook returned successfully!\n";
                    pause();
                    return;
                }
            }
        }
    } else {
        std::cout << "\n\t\t\tBook not issued to the specified student!\n";
        pause();
    }
}
void Library::viewIssuedBooksHistory() {
    headMessage("View Issued History");
    std::ifstream file("issued_books.txt");
    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        if (file.tellg() < 1) {
            std::cout << "\n\t\t\tNo issued history found!\n";
        } else {
            file.clear();
            file.seekg(0, std::ios::beg);
            int id, book;
            std::time_t issueTime;
            int i = 0;
            while (file >> id >> book >> issueTime) {
                std::cout << "\n\n\t\t\t\t\t\t********** " << ++i << ". ********** \n";
                std::cout << "\n\n\t\t\tStudent ID: " << id;
                std::cout << "\n\n\t\t\tBook ID: " << book;
                std::cout << "\n\n\t\t\tIssue Time: " << std::ctime(&issueTime);
            }
        }
        file.close();
    } else {
        std::cout << "\n\n\t\t\tFile Not Found!\n";
    }
    pause();
}

void Library::saveBookData() {
    std::ofstream file("books.txt");
    if (file.is_open()) {
        for (const auto& book : books) {
            file << book.bookID << ","
                 << book.bookName << ","
                 << book.authorName << ","
                 << book.quantity << "\n";
        }
        file.close();
    }
}

void Library::loadBookData() {
    std::ifstream file("books.txt");
    if (file.is_open()) {
        books.clear();
        bookCount = 0;
        std::string line;

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;

            Books newBook;

            std::getline(ss, token, ',');
            newBook.bookID = std::stoi(token);

            std::getline(ss, newBook.bookName, ',');
            std::getline(ss, newBook.authorName, ',');

            std::getline(ss, token, ',');
            newBook.quantity = std::stoi(token);

            books.push_back(newBook);
            bookCount++;
        }
        file.close();
    }
}
