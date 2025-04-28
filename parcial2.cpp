// SISTEMA QUE LEE TRES MATRCES DE 4 * 3
#include <iostream>
using namespace std;
int main() {
    // Definir el almacen con 3 estantes...
    int almacen[3][4][5] = {
        {//Estante 0
            {11, 12, 14, 18, 14},
            {18, 14, 19, 11, 13},
            {10, 12, 14, 19, 13},
            {13, 18, 23, 18, 17}
        },
        {//Estante 1
            {11, 18, 15, 16, 16},
            {16, 14, 19, 16, 14},
            {10, 12, 14, 19, 11},
            {14, 11, 12, 14, 15}
        },
        {//Estante 2
            {14, 14, 13, 15, 17},
            {12, 15, 19, 18, 15},
            {16, 14, 15, 12, 11},
            {12, 11, 13, 17, 23}
        }
    };
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << "--- Menu de opciones ---\n";
        cout << "1. Contar unidades de un juguete\n";
        cout << "2. Contar juguetes diferente en un estante\n";
        cout << "3. Verificar cantidad de productos con stock 0\n";
        cout << "4. Mostrar todo el almacen\n";
        cout << "5. Salir\n";
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int codigo;
                cout << "Ingrese el codigo del juguete a contar: ";
                cin >> codigo;

                int contador = 0;
                cout << "El juguete " << codigo << " se encuentra en: \n";
                for (int e=0; e<3; e++) {
                    int conteoEstante = 0;
                    for (int f=0; f<4; f++) {
                        for (int c=0; c<5; c++) {
                            if (almacen[e][f][c] == codigo) {
                                conteoEstante++;
                                contador++;
                                cout << "Estante: " << e << "; fila: " << f << "; columna: " << c << endl;
                            }
                        }
                    }
                    if (conteoEstante > 0) {
                        cout << "El estante: " << e << " tiene " << conteoEstante << " unidades\n";
                        // Se quitó el break para permitir contar en todos los estantes
                    }
                }
                cout << "Total general: " << contador << " Unidades\n";
                break;
            }
            case 2: {
                int estante;
                do {
                    cout << "Ingrese el numero del estante: ";
                    cin >> estante;
                } while (!(estante >= 0 && estante <= 2));
                bool codigos_encontrados[50] = {false};
                int totalCodigos = 0;
                for (int f=0; f<4; f++) {
                    for (int c=0; c<5; c++) {
                        int codigo = almacen[estante][f][c];
                        if (!codigos_encontrados[codigo]) {
                            codigos_encontrados[codigo]=true;
                            totalCodigos++;
                        }
                    }
                }
                cout << "Codigos diferentes en el estante: " << estante << " = " << totalCodigos;
                cout << "Los codigos son: ";
                for (int i = 0; i<50; i++) {
                    if (codigos_encontrados[i]) {
                        cout << i << " ";
                    }
                }
                cout << endl;
                break;
            }
            case 3: {
                cout << "Verificando juguetes con stock cero...\n";
                int conteoJuguetes[50] = {0};
                for (int e = 0; e<3; e++) {  // Corregido para incluir los 3 estantes
                    for (int f=0; f<4; f++) {
                        for (int c=0; c<5; c++) {
                            int codigo = almacen[e][f][c];
                            conteoJuguetes[codigo]++;
                        }
                    }
                }
                bool hayStockCero = false;
                for (int i = 1; i < 50; i++) {
                    if (conteoJuguetes[i] == 0) {
                        cout << "El juguete " << i << " tiene stock cero\n";
                        hayStockCero = true;
                    }
                }  // Agregada la llave faltante
                if (!hayStockCero) {
                    cout << "No hay juguetes con stock cero\n";
                }
                break;
            }
            case 4: {
                cout << "Contenido del almacen: " << endl;
                for (int e = 0; e < 3; e++) {
                    cout << "\nEstante " << e << ":\n";
                    
                    for (int f = 0; f < 4; f++) {
                        for (int c = 0; c < 5; c++) {
                            cout << almacen[e][f][c] << "\t";
                        }
                        cout << endl;
                    }
                }
                break;
            } 
            case 5:
                salir = true;
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
    return 0;
}