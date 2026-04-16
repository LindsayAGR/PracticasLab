#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
using namespace std;

unsigned char rotarIzquierda(unsigned char c, int n);
unsigned char rotarDerecha(unsigned char c, int n);

string encriptar(const string& texto, int n, unsigned char clave);
string desencriptar(const string& texto, int n, unsigned char clave);

#endif // CRYPTO_H
