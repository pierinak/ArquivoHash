#ifndef EMPRESTIMOS_H
#define EMPRESTIMOS_H

#include <iostream>
#include <cstring>
#define TABLE_SIZE 11

using namespace std;

struct Emprestimo {
    int isbn;
    int userId;
    char dataEmprestimo[11];
    char dataDevolucao[11];
};

int hashEmprestimos(int isbn);
void initEmprestimos(Emprestimo* emprestimos);
void registrarEmprestimo(Emprestimo* emprestimos, Emprestimo emprestimo, int index);
void devolverEmprestimo(Emprestimo* emprestimos, int isbn);
void mostrarEmprestimos(Emprestimo* emprestimos);

int hashEmprestimos(int isbn) {
    return isbn % TABLE_SIZE;
}

void initEmprestimos(Emprestimo* emprestimos) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        emprestimos[i].isbn = -1;
        emprestimos[i].userId = -1;
        strcpy(emprestimos[i].dataEmprestimo, "");
        strcpy(emprestimos[i].dataDevolucao, "");
    }
}

void registrarEmprestimo(Emprestimo* emprestimos, Emprestimo emprestimo, int index) {
    emprestimos[index] = emprestimo;
}

void devolverEmprestimo(Emprestimo* emprestimos, int isbn) {
    int index = hashEmprestimos(isbn);
    if (emprestimos[index].isbn == isbn) {
        emprestimos[index].isbn = -1;
        emprestimos[index].userId = -1;
        strcpy(emprestimos[index].dataEmprestimo, "");
        strcpy(emprestimos[index].dataDevolucao, "");
    }
}

void mostrarEmprestimos(Emprestimo* emprestimos) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (emprestimos[i].isbn != -1) {
            cout << "ISBN: " << emprestimos[i].isbn << ", User ID: " << emprestimos[i].userId
                 << ", Data Empréstimo: " << emprestimos[i].dataEmprestimo << ", Data Devolução: "
                 << emprestimos[i].dataDevolucao << endl;
        }
    }
}

#endif
