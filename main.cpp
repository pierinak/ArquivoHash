#include <iostream>
#include <locale>
#include <limits>
#include "livros.h"
#include "usuarios.h"
#include "emprestimos.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Inicializar as tabelas
    Livro livros[TABLE_SIZE];
    Usuario usuarios[TABLE_SIZE];
    Emprestimo emprestimos[TABLE_SIZE];

    initLivros(livros);
    initUsuarios(usuarios);
    initEmprestimos(emprestimos);

    int op = -1;

    while (op != 0) {
        cout << "0-Sair\n";
        cout << "1-Cadastrar Livro\n";
        cout << "2-Remover Livro\n";
        cout << "3-Buscar Livro\n";
        cout << "4-Listar Livros\n";
        cout << "5-Cadastrar Usuário\n";
        cout << "6-Remover Usuário\n";
        cout << "7-Buscar Usuário\n";
        cout << "8-Listar Usuários\n";
        cout << "9-Registrar Empréstimo\n";
        cout << "10-Devolver Livro\n";
        cout << "11-Listar Empréstimos\n";
        cout << "Opção: ";
        cin >> op;

        // Limpar o buffer de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int isbn, id;
        char buffer[100];
        Livro livro;
        Usuario usuario;
        Emprestimo emprestimo;

        switch (op) {
            case 0:
                cout << "Fim\n";
                break;
            case 1:
                cout << "Cadastrar Livro\n";
                cout << "ISBN: ";
                cin >> livro.isbn;
                cout << "Título: ";
                cin.ignore();
                cin.getline(livro.titulo, 100);
                cout << "Autor: ";
                cin.getline(livro.autor, 100);
                cout << "Páginas: ";
                cin >> livro.paginas;
                insereLivro(livros, livro, hashLivros(livro.isbn));
                break;
            case 2:
                cout << "Remover Livro\n";
                cout << "ISBN: ";
                cin >> isbn;
                removerLivro(livros, isbn);
                break;
            case 3:
                cout << "Buscar Livro\n";
                cout << "ISBN: ";
                cin >> isbn;
                Livro* encontrado;
                encontrado = buscarLivro(livros, isbn);
                if (encontrado) {
                    cout << "Livro encontrado: " << encontrado->titulo << " de " << encontrado->autor << endl;
                } else {
                    cout << "Livro não encontrado\n";
                }
                break;
            case 4:
                cout << "Listar Livros\n";
                mostrarLivros(livros);
                break;
            case 5:
                cout << "Cadastrar Usuário\n";
                cout << "ID: ";
                cin >> usuario.id;
                cout << "Nome: ";
                cin.ignore();
                cin.getline(usuario.nome, 100);
                cout << "Contato: ";
                cin.getline(usuario.contato, 100);
                insereUsuario(usuarios, usuario, hashUsuarios(usuario.id));
                break;
            case 6:
                cout << "Remover Usuário\n";
                cout << "ID: ";
                cin >> id;
                removerUsuario(usuarios, id);
                break;
            case 7:
                cout << "Buscar Usuário\n";
                cout << "ID: ";
                cin >> id;
                Usuario* usuarioEncontrado;
                usuarioEncontrado = buscarUsuario(usuarios, id);
                if (usuarioEncontrado) {
                    cout << "Usuário encontrado: " << usuarioEncontrado->nome << ", Contato: " << usuarioEncontrado->contato << endl;
                } else {
                    cout << "Usuário não encontrado\n";
                }
                break;
            case 8:
                cout << "Listar Usuários\n";
                mostrarUsuarios(usuarios);
                break;
            case 9:
                cout << "Registrar Empréstimo\n";
                cout << "ISBN: ";
                cin >> emprestimo.isbn;
                cout << "ID do Usuário: ";
                cin >> emprestimo.userId;
                cout << "Data do Empréstimo: ";
                cin.ignore();
                cin.getline(emprestimo.dataEmprestimo, 11);
                cout << "Data de Devolução: ";
                cin.getline(emprestimo.dataDevolucao, 11);
                registrarEmprestimo(emprestimos, emprestimo, hashEmprestimos(emprestimo.isbn));
                break;
            case 10:
                cout << "Devolver Livro\n";
                cout << "ISBN: ";
                cin >> isbn;
                devolverEmprestimo(emprestimos, isbn);
                break;
            case 11:
                cout << "Listar Empréstimos\n";
                mostrarEmprestimos(emprestimos);
                break;
            default:
                cout << "Opção inválida!\n";
                break;
        }
    }

    return 0;
}
