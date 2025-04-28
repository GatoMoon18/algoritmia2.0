// ALGORITMO PARA ALMACENAR LOS DIGITOS DE DOS NUMEROS Y CREE UN TERCER ARREGLO CON LA DIFERENCIA SIMETRICA DE LOS DOS ANTERIORES MOSTRAR EL NUMERO FORMADO CON EL TERCER ARREGLO DE MENOR A MAYOR.
#include <iostream>
using namespace std;
int main() {
    // INGRESANDO LOS NUMEROS

    int n1, n2;
    cout << "Ingrese el primer numero: ";
    cin >> n1;
    cout << "Ingrese el segundo numero: ";
    cin >> n2;

    // VALIDANDO LOS DIGITOS UNIOS DE CADA NUMERO
    bool digitos1[10] = {false};
    bool digitos2[10] = {false};
    int temp1 = n1;
    while (temp1>0) {
        int dig = temp1 % 10;
        digitos1[dig] = true;
        temp1 /= 10;
    }
    int temp2 = n2;
    while (temp2>0) {
        int dig = temp2 % 10;
        digitos2[dig] = true;
        temp2 /= 10;
    }
    // MOSTRANDO DIGITOS VALIDOS
    cout << "Los digitos unicos del primer numero son: ";
    for (int i = 0; i < 10; i++) {
        if (digitos1[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Los digitos unicos del segundo numero son: ";
    for (int i = 0; i < 10; i++) {
        if (digitos2[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    // DIFERENCIA SIMETRICA
    bool diferencia_simetrica[10] = {false};
    for (int i = 0; i < 10; i++) {
        if (digitos1[i] != digitos2[i]) {
            diferencia_simetrica[i] = true;
        }
    }
    cout << "La diferencia simetrica de los numeros es: ";
    for (int i = 0; i < 10; i++) {
        if (diferencia_simetrica[i]) {
            cout << i << " ";
        }
    }
    return 0;
}