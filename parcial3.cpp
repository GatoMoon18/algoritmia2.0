// 1. Se desea almacenar los elementos de dos conjuntos de enteros. Luego presentar la unión, intersección y diferencia. Para el ingreso e datos, estos debenquedar en orden creciente e igual para la presentación de la unión, intersección y diferencia:
#include <iostream>
using namespace std;
int main() {
    // Almacenando conjuntos.
    int A, B;
    cout << "Ingrese la cantidad de elementos del conjunto A: ";
    cin >> A;
    cout << "Ingrese la cantidad de elementos del conjunto B: ";
    cin >> B;
    int conjuntoA[A];
    int conjuntoB[B];
    // Ingresando elementos.
    cout << "Ingresando elementos del conjunto A" << endl;
    for (int i=0; i<A; i++) {
        cout << "Ingrese el elemento #" << (i+1) << ": ";
        cin >> conjuntoA[i];
    }
    cout << "Ingresando elementos del conjunto B" << endl;
    for (int i=0; i<B; i++) {
        cout << "Ingrese el elemento #" << (i+1) << ": ";
        cin >> conjuntoB[i];
    }
    // Orden creciente.
    for (int i=0; i<A; i++) {
        for (int j = i+1; j<A-1;j++) {
            if (conjuntoA[i] > conjuntoA[j]) {
                int aux = conjuntoA[i];
                conjuntoA[i] = conjuntoA[j];
                conjuntoA[j] = aux;
            }
        }
    }
    for (int i=0; i<B-1; i++) {
        for (int j = i+1; j<B;j++) {
            if (conjuntoB[i] > conjuntoB[j]) {
                int aux = conjuntoB[i];
                conjuntoB[i] = conjuntoB[j];
                conjuntoB[j] = aux;
            }
        }
    }
    // Mostrar conjuntos.
    cout << "Conjunto A- " << endl;
    cout << "Numero de elementos: " << A << endl;
    cout << "Se almacena: ";
    for (int i=0; i<A; i++) {
        bool repetido = false;
        for (int j=i+1; j<A; j++) {
            if (conjuntoA[i] == conjuntoA[j]) {
                repetido = true;
                break;
            }
        }
        if (!repetido) {
            cout << conjuntoA[i] << "; "; 
        }
    }
    cout << endl;
    cout << "Conjunto B- " << endl;
    cout << "Numero de elementos: " << B << endl;
    cout << "Se almacena: ";
    for (int i=0; i<B; i++) {
        cout << conjuntoB[i] << "; "; 
    }
    cout << endl;

    // Union.
    for (int i=0; i<A; i++) {
        bool enConjuntoA = false;
        for (int j = 0; j<B; j++) {

        }
    }
    return 0;

}