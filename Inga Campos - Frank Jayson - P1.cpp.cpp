#include <iostream>
using namespace std;

int main() {
    int matriz[3][3];
	int i,j;
    cout << "Digite los numeros enteros de la matriz 3x3: \n" << endl;
    for (i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            cout << "Posicion [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "\nLa matriz inicial es:" << endl;
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
        	if(i==j)
            matriz[i][j]=0;
        }
    }
    cout << "\nMatriz modificada:" << endl;
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

