#ifndef USUARIOS_H
#define USUARIOS_H

#include <iostream>
#include <cstring>
#define TABLE_SIZE 11

using namespace std;

struct Usuario {
    int id;
    char nome[100];
    char contato[100];
};

int hashUsuarios(int id);
void initUsuarios(Usuario* usuarios);
void insereUsuario(Usuario* usuarios, Usuario usuario, int index);
Usuario* buscarUsuario(Usuario* usuarios, int id);
void removerUsuario(Usuario* usuarios, int id);
void mostrarUsuarios(Usuario* usuarios);

int hashUsuarios(int id) {
    return id % TABLE_SIZE;
}

void initUsuarios(Usuario* usuarios) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        usuarios[i].id = -1;
        strcpy(usuarios[i].nome, "");
        strcpy(usuarios[i].contato, "");
    }
}

void insereUsuario(Usuario* usuarios, Usuario usuario, int index) {
    usuarios[index] = usuario;
}

Usuario* buscarUsuario(Usuario* usuarios, int id) {
    int index = hashUsuarios(id);
    if (usuarios[index].id == id) {
        return &usuarios[index];
    }
    return nullptr;
}

void removerUsuario(Usuario* usuarios, int id) {
    int index = hashUsuarios(id);
    if (usuarios[index].id == id) {
        usuarios[index].id = -1;
        strcpy(usuarios[index].nome, "");
        strcpy(usuarios[index].contato, "");
    }
}

void mostrarUsuarios(Usuario* usuarios) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (usuarios[i].id != -1) {
            cout << "ID: " << usuarios[i].id << ", Nome: " << usuarios[i].nome << ", Contato: " << usuarios[i].contato << endl;
        }
    }
}

#endif
