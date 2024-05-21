#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct Loan {
    string bookTitle;
    string userId;
    string loanDate;
    string returnDate;

    Loan() = default;
    Loan(const string& bookTitle, const string& userId, const string& loanDate, const string& returnDate)
        : bookTitle(bookTitle), userId(userId), loanDate(loanDate), returnDate(returnDate) {}
};

class LoanCollection {
public:
    void addLoan(const Loan& loan);
    void removeLoan(const string& bookTitle, const string& userId);
    vector<Loan> listLoans() const;

private:
    vector<Loan> loans;
};

#endif // LOAN_H
