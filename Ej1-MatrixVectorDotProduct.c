#include <stdio.h>
#include <stdlib.h> //Para malloc
/*
Observación: Los arreglos  definidos por malloc son distintos a los arreglos definidos por arr[i][j],
	los primeros están disperados a lo largo de la memoria, en el segundo los espacios de memoria de estám juntos.
Cambio sin importancia
*/

void ver_matriz(float** matriz, int n, int m){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%f  ", *(*(matriz + i) + j) );
		}
	printf("\n");
	}
}

/*
Devuelve una arreglo donde cada elemento es el producto punto de una fila
de 'a' con 'b'.
Si el número de columnas de 'a' no coincide con la longitud de 'b', devuelve -1.

Input:
	a (float**): Matriz nxm
	b (float**): Matriz mxk
	n (int): Numero filas matriz A
	m (int): Numero columnas a y filas b
	k (int): numero columnas b

return:
	float** : Resultado de ab.
*/

float**  matrix_dot_vector(float** a, float** b, int n, int m,  int k){
	// Definicion
	float** resultado = malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++){
		*(resultado + i) = malloc(k * sizeof(float));
	}
	// Operacion
	for (int i = 0; i < n; i++){
		for (int j = 0; j < k; j++){
			*(*(resultado + i) + j ) = 0.0;
			for (int l = 0; l < m; l++){
				*(*(resultado + i) + j) += *(*(a + i) + l) * *(*(b + l) + j);
			}
		}
	}
	return resultado;
}


int main(void){
	/* Definimos la matriz a
	(manejable como argumento de funciones)
	*/
	int filas = 2, columnas = 4;
	float** a = malloc(filas * sizeof(float*));
	for (int i = 0; i < filas; i++){
		*(a + i)  = malloc(columnas * sizeof(float));
	}
	float matriz_estatica[2][4] = {{0.0, 3.7, 0.0, -1.0/3.0},{0.2 ,1.1 ,-1.0 ,1.7}};
	/*
	Observación: Si se quiere declarar una matriz como la de arriba de tamaño variable
	primero se declara y luego se inicializa
	*/

	// Tenemos asignada la memoria para matriz, falta inicializarla con valores,
	// usemos los de matriz_estatica
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
		*( *(a + i) + j) = *(*(matriz_estatica + i) + j);
		}
	}

	// Definimos b
	float** b = malloc(4 * sizeof(float*));
	for (int i = 0; i < 4; i++){
		*(b+i) = malloc(sizeof(float));
	}
	**b = 1.0;
	**(b+1) = -1.0;
	**(b+2) = 2.0;
	**(b+3) = 0.0;
	// Operacion ab
	float** ab = matrix_dot_vector(a, b, filas, columnas, 1);
	ver_matriz(ab, filas, 1);

	return  0;
}
