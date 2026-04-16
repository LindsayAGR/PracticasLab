
#include "lz78.h"
#include <iostream>
using namespace std;

string compressLZ78(const string& input) {
    string diccionario[1000];
    int size = 0;

    string resultado = "";
    string actual = "";

    for (char c : input) {
        actual += c;

        bool existe = false;
        for (int i = 0; i < size; i++) {
            if (diccionario[i] == actual) {
                existe = true;
                break;
            }
        }

        if (!existe) {
            diccionario[size++] = actual;
            resultado += actual + "|";
            actual = "";
        }
    }

    return resultado;
}

string decompressLZ78(const string& input) {
    string resultado = "";
    string palabra = "";

    for (char c : input) {
        if (c == '|') {
            resultado += palabra;
            palabra = "";
        } else {
            palabra += c;
        }
    }

    return resultado;
}
