#include <iostream>
using namespace std;
int main(){
    // PEDIR EL NUMERO:
    int cifras = 0;
    long n;
    do {
        cout << "Ingrese el numero n: ";
        cin >> n;
    } while (!(n>=100));
    int original = n;
    // CONTAR CIFRAS:
    int temp = n;
    while (temp > 0) {
        temp /= 10;
        cifras++;
    }
    // CREAR EL ARREGLO:
    int numero[cifras];
    for (int i=0; i<cifras; i++){
        numero[i] = n % 10;
        n /= 10;
    }

    // ORDENAR DE MAYOR A MENOR:
    for (int i = 0; i < cifras - 1; i++) {
        for (int j = i + 1; j < cifras; j++) {
            if (numero[j] > numero[i]) {
                int aux = numero[i];
                numero[i] = numero[j];
                numero[j] = aux;
            }
        }
    }

    // SELECCIONAR LA MEDIANA:
    int mediana;
    if (cifras % 2 == 1) {  // Número impar de cifras
        mediana = numero[cifras / 2];
    } else {  // Número par de cifras
        int suma = numero[cifras / 2 - 1] + numero[cifras / 2];
        // Implementación manual del redondeo
        mediana = suma / 2;
        if (suma % 2 == 1) {  // Si la suma es impar, redondear hacia arriba
            mediana++;
        }
    }


    // CONSTRUIR EL NÚMERO MODIFICADO (sin los dígitos que coinciden con la mediana)
    long modificado = 0;
    temp = original;
    long posicion = 1;
    
    while (temp > 0) {
        int digito = temp % 10;
        if (digito != mediana) {
            modificado += digito * posicion;
            posicion *= 10;
        }
        temp /= 10;
    }
    
    // IMPRIMIR RESULTADOS
    cout << "El numero original: " << original << endl;
    cout << "El numero modificado: " << modificado << endl;
    
    return 0;
}