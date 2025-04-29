// Para una matriz A cuadrada de orden n (n<=20), se desea almacenar sus elementos reales. Luego presentear el resultado de la siguiente operación: A^3 + A^2 + A.
#include <iostream>
using namespace std;
int main() {
    // CREANDO LA MATRIZ N:
    int n;
    do {
        cout << "Ingrese el orden de la matriz: ";
        cin >> n;
    } while (!(n>0 && n<=20));
    double A[n][n], A2[n][n], A3[n][n], RESULTADO[n][n], temp[n][n];
    // INSERTANDO ELEMENTOS EN LA MATRIZ N:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Ingresando elemento A[" << i << "]" << "[" << j << "]: ";
            cin >> A[i][j];
        }
    }
    // MOSTRANDO LA MATRIZ A:
    cout << "- MATRIZ A -" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    // CALCULANDO A CUADRADO
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A2[i][j] = 0;
            for (int k = 0; k < n; k++) {
                A2[i][j] += A[i][k] * A[k][j];
            }
        }
    }
    // CALCULANDO LA MATRIZ A CUBO
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                A3[i][j] += A2[i][k] * A2[k][j]; 
            }
        }
    }
    // CALCULANDO LA SUMA TOTAL 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = A[i][j] + A2[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            RESULTADO[i][j] = temp[i][j] + A3[i][j];
        }
    }
    // IMPRIMIENDO RESULTADOS
    cout << "RESULTADO --- (A3 + A2 + A)" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << RESULTADO[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}