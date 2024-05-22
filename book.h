#ifndef LIVROS_H
#define LIVROS_H

#include <iostream>
#include <cstring>
#define TABLE_SIZE 11

using namespace std;

struct Livro {
    int isbn;
    char titulo[100];
    char autor[100];
    int paginas;
};

int hashLivros(int isbn);
void initLivros(Livro* livros);
void insereLivro(Livro* livros, Livro livro, int index);
Livro* buscarLivro(Livro* livros, int isbn);
void removerLivro(Livro* livros, int isbn);
void mostrarLivros(Livro* livros);

int hashLivros(int isbn) {
    return isbn % TABLE_SIZE;
}

void initLivros(Livro* livros) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        livros[i].isbn = -1;
        strcpy(livros[i].titulo, "");
        strcpy(livros[i].autor, "");
        livros[i].paginas = 0;
    }
}

void insereLivro(Livro* livros, Livro livro, int index) {
    livros[index] = livro;
}

Livro* buscarLivro(Livro* livros, int isbn) {
    int index = hashLivros(isbn);
    if (livros[index].isbn == isbn) {
        return &livros[index];
    }
    return nullptr;
}

void removerLivro(Livro* livros, int isbn) {
    int index = hashLivros(isbn);
    if (livros[index].isbn == isbn) {
        livros[index].isbn = -1;
        strcpy(livros[index].titulo, "");
        strcpy(livros[index].autor, "");
        livros[index].paginas = 0;
    }
}

void mostrarLivros(Livro* livros) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (livros[i].isbn != -1) {
            cout << "ISBN: " << livros[i].isbn << ", Título: " << livros[i].titulo
                 << ", Autor: " << livros[i].autor << ", Páginas: " << livros[i].paginas << endl;
        }
    }
}

#endif
