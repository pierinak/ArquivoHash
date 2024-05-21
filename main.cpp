#include "Book.h"
#include "User.h"
#include "Loan.h"
#include <iostream>

using namespace std;

int main() {
    BookCollection books;
    UserCollection users;
    LoanCollection loans;

    // Exemplo de uso
    books.addBook(Book("123456789", "The Great Gatsby", "F. Scott Fitzgerald", 218));
    users.addUser(User("001", "John Doe", "john@example.com"));
    loans.addLoan(Loan("The Great Gatsby", "001", "2024-05-21", "2024-06-21"));

    cout << "Books in the library:" << endl;
    books.listBooks();

    cout << "\nUsers in the library:" << endl;
    users.listUsers();

    cout << "\nLoans in the library:" << endl;
    for (const auto& loan : loans.listLoans()) {
        cout << "Book: " << loan.bookTitle << ", User ID: " << loan.userId 
             << ", Loan Date: " << loan.loanDate << ", Return Date: " << loan.returnDate << endl;
    }

    return 0;
}
