#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string subject;
    int book_id;
};

int main() {
    Book book1, book2;

    cout << "Enter details for the first book:" << endl;
    cout << "Title: ";
    getline(cin, book1.title);
    cout << "Author: ";
    getline(cin, book1.author);
    cout << "Subject: ";
    getline(cin, book1.subject);
    cout << "Book ID: ";
    cin >> book1.book_id;
    cin.ignore();

    cout << "\nEnter details for the second book:" << endl;
    cout << "Title: ";
    getline(cin, book2.title);
    cout << "Author: ";
    getline(cin, book2.author);
    cout << "Subject: ";
    getline(cin, book2.subject);
    cout << "Book ID: ";
    cin >> book2.book_id;
    cin.ignore();

    cout << "\nDetails of the first book:" << endl;
    cout << "Title: " << book1.title << endl;
    cout << "Author: " << book1.author << endl;
    cout << "Subject: " << book1.subject << endl;
    cout << "Book ID: " << book1.book_id << endl << endl;

    cout << "Details of the second book:" << endl;
    cout << "Title: " << book2.title << endl;
    cout << "Author: " << book2.author << endl;
    cout << "Subject: " << book2.subject << endl;
    cout << "Book ID: " << book2.book_id << endl;

    return 0;
}

