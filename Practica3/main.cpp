#include <iostream>
#include "rle.h"
#include "lz78.h"
#include "crypto.h"
#include "gestorArchivos.h"

using namespace std;

int main() {

    // 1. Leer archivo
    string texto = leerArchivo("entrada.txt");

    // Validar archivo
    if (texto == "") {
        cout << "ERROR: No se encontro el archivo entrada.txt o esta vacio" << endl;
        return 0;
    }

    // 2. Comprimir con RLE
    string comprimidoRLE = compressRLE(texto);

    // 3. Comprimir con LZ78
    string comprimidoLZ = compressLZ78(comprimidoRLE);

    // 4. Encriptar
    string encriptado = encriptar(comprimidoLZ, 2, 'K');

    // 5. Desencriptar
    string desencriptado = desencriptar(encriptado, 2, 'K');

    // 6. Descomprimir LZ78
    string desLZ = decompressLZ78(desencriptado);

    // 7. Descomprimir RLE
    string final = decompressRLE(desLZ);

    //8. CREAR SALIDA PASO A PASO
    string salida = "";

    salida += "===== PROCESO COMPLETO =====\n\n";

    salida += "TEXTO ORIGINAL:\n" + texto + "\n\n";
    salida += "RLE:\n" + comprimidoRLE + "\n\n";
    salida += "LZ78:\n" + comprimidoLZ + "\n\n";
    salida += "ENCRIPTADO:\n" + encriptado + "\n\n";
    salida += "DESENCRIPTADO:\n" + desencriptado + "\n\n";
    salida += "LZ78 DECODIFICADO:\n" + desLZ + "\n\n";
    salida += "TEXTO FINAL:\n" + final + "\n\n";

    // 9. Guardar en archivo
    escribirArchivo("salida.txt", salida);

    // 10. Mostrar en consola
    cout << salida;

    // 11. Verificación final
    if (texto == final) {
        cout << "TODO FUNCIONA PERFECTO " << endl;
    } else {
        cout << "ERROR " << endl;
    }

    return 0;
}
