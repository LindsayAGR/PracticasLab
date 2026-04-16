#include "gestorArchivos.h"
#include <fstream>
#include <iostream>

using namespace std;

string leerArchivo(const string& nombre) {
    ifstream file(nombre);
    string contenido = "", linea;

    if (file.is_open()) {
        while (getline(file, linea)) {
            contenido += linea + "\n";
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo\n";
    }

    return contenido;
}

void escribirArchivo(const string& nombre, const string& contenido) {
    ofstream file(nombre);

    if (file.is_open()) {
        file << contenido;
        file.close();
    } else {
        cout << "No se pudo escribir el archivo\n";
    }
}
