#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Book {
public:
    T bookId;
    string title;
    string author;

    Book(T id, string t, string a) : bookId(id), title(t), author(a) {}

    bool operator==(const Book &other) const {
        return this->bookId == other.bookId;
    }

    friend ostream& operator<<(ostream &os, const Book &b) {
        os << "Book ID: " << b.bookId << ", Title: " << b.title << ", Author: " << b.author;
        return os;
    }
};

template <typename T>
class Library {
private:
    vector<Book<T>> books;

public:
    void addBook(const Book<T> &book) {
        for (const auto &b : books) {
            if (b == book) {
                cout << "Book with ID " << book.bookId << " already exists.\n";
                return;
            }
        }
        books.push_back(book);
        cout << "Book added to the library.\n";
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (const auto &b : books) {
            cout << b << endl;
        }
    }
};

int main() {
    Library<int> library;  
    Book<int> book1(101, "Atomic Habits", "James Clear");
    Book<int> book2(102, "The Secret", "Rhonda Byrne");
    Book<int> book3(103, "The Alchemist", "Paulo Coelho");
    Book<int> book4(101, "Start with Why", "Simon Sinek"); // Duplicate ID

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4); 

    cout << "\nBooks in the library:\n";
    library.displayBooks();

    return 0;
}
