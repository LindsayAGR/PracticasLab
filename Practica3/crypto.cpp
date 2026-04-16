#include "crypto.h"

unsigned char rotarIzquierda(unsigned char c, int n) {
    return (c << n) | (c >> (8 - n));
}

unsigned char rotarDerecha(unsigned char c, int n) {
    return (c >> n) | (c << (8 - n));
}

string encriptar(const string& texto, int n, unsigned char clave) {
    string resultado = texto;

    for (int i = 0; i < resultado.size(); i++) {
        unsigned char c = resultado[i];

        c = rotarIzquierda(c, n);
        c = c ^ clave;

        resultado[i] = c;
    }

    return resultado;
}

string desencriptar(const string& texto, int n, unsigned char clave) {
    string resultado = texto;

    for (int i = 0; i < resultado.size(); i++) {
        unsigned char c = resultado[i];

        c = c ^ clave;
        c = rotarDerecha(c, n);

        resultado[i] = c;
    }

    return resultado;
}
