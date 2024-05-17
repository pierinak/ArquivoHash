
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm> // Adicionando inclusão do cabeçalho <algorithm>


using namespace std;

struct Livro {
    string titulo;
    string autor;
    int num_paginas;
    // Outras informações relevantes
};

struct Usuario {
    string nome;
    string contato;
    // Outras informações relevantes
};

struct Emprestimo {
    string titulo_livro;
    string id_usuario;
    string data_emprestimo;
    string data_devolucao_prevista;
};

class Biblioteca {
private:
    unordered_map<string, Livro> livros;
    unordered_map<string, Usuario> usuarios;
    vector<Emprestimo> emprestimos;

public:
    void cadastrarLivro(string isbn, string titulo, string autor, int num_paginas) {
        Livro novoLivro;
        novoLivro.titulo = titulo;
        novoLivro.autor = autor;
        novoLivro.num_paginas = num_paginas;
        livros[isbn] = novoLivro;
    }

    void removerLivro(string isbn) {
        livros.erase(isbn);
    }

    Livro* buscarLivro(string isbn) {
        if (livros.find(isbn) != livros.end()) {
            return &livros[isbn];
        }
        return nullptr;
    }

    void cadastrarUsuario(string id_usuario, string nome, string contato) {
        Usuario novoUsuario;
        novoUsuario.nome = nome;
        novoUsuario.contato = contato;
        usuarios[id_usuario] = novoUsuario;
    }

    void removerUsuario(string id_usuario) {
        usuarios.erase(id_usuario);
    }

    Usuario* buscarUsuario(string id_usuario) {
        if (usuarios.find(id_usuario) != usuarios.end()) {
            return &usuarios[id_usuario];
        }
        return nullptr;
    }

    void registrarEmprestimo(string titulo_livro, string id_usuario, string data_emprestimo, string data_devolucao_prevista) {
        Emprestimo novoEmprestimo;
        novoEmprestimo.titulo_livro = titulo_livro;
        novoEmprestimo.id_usuario = id_usuario;
        novoEmprestimo.data_emprestimo = data_emprestimo;
        novoEmprestimo.data_devolucao_prevista = data_devolucao_prevista;
        emprestimos.push_back(novoEmprestimo);
    }

    void devolverLivro(string titulo_livro, string id_usuario) {
        emprestimos.erase(
            remove_if(
                emprestimos.begin(),
                emprestimos.end(),
                [&](const Emprestimo& e) { return e.titulo_livro == titulo_livro && e.id_usuario == id_usuario; }),
            emprestimos.end());
    }

    void consultarLivro(string isbn) {
        Livro* livro = buscarLivro(isbn);
        if (livro != nullptr) {
            cout << "Título: " << livro->titulo << endl;
            cout << "Autor: " << livro->autor << endl;
            cout << "Número de páginas: " << livro->num_paginas << endl;
            // Imprimir outras informações relevantes, se houver
        } else {
            cout << "Livro não encontrado." << endl;
        }
    }

    void listarTodosLivros() {
        cout << "Lista de Livros Disponíveis:" << endl;
        for (auto& livro : livros) {
            cout << "ISBN: " << livro.first << ", Título: " << livro.second.titulo << endl;
        }
    }

    void consultarUsuario(string id_usuario) {
        Usuario* usuario = buscarUsuario(id_usuario);
        if (usuario != nullptr) {
            cout << "Nome: " << usuario->nome << endl;
            cout << "Contato: " << usuario->contato << endl;
            // Imprimir outras informações relevantes, se houver
        } else {
            cout << "Usuário não encontrado." << endl;
        }
    }
};

int main() {
    Biblioteca biblioteca;

    // Exemplo de uso:
    biblioteca.cadastrarLivro("978-0547928227", "The Hobbit", "J.R.R. Tolkien", 310);
    biblioteca.cadastrarUsuario("123456789", "Frodo Baggins", "frodo@shire.com");
    biblioteca.registrarEmprestimo("The Hobbit", "123456789", "2024-05-17", "2024-06-17");

    biblioteca.consultarLivro("978-0547928227");
    biblioteca.listarTodosLivros();
    biblioteca.consultarUsuario("123456789");

    return 0;
}
