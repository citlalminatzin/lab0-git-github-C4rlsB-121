#include <stdio.h>
#include <stdlib.h> //Para malloc

/*
Devuelve una arreglo donde cada elemento es el producto punto de una fila
de 'a' con 'b'.
Si el número de columnas de 'a' no coincide con la longitud de 'b', devuelve -1.

Input:
	Un arreglo
*/

float**  matrix_dot_vector(float** a, int filas, int columnas){
	printf("Tamaño de a: %f", sizeof(a));
}

void main(){
	/* Definimos la matriz a
	(manejable como argumento de funciones)
	*/
	int filas = 2, columnas = 4;
	float** a = malloc(filas * sizeof(float*));
	for (int i=0; i < filas; i++){
		a[i] = malloc(columnas * sizeof(float));

	/* Dificil para manejar con funciones pues el tamaño de
	 la matríz está 'anclado' al tipo de dato.
	*/
	float matriz_estatica[2][4] = {{2.0, 3.7, 0.0, -1.0/3.0},{0.2 ,1.1 ,-1.0 ,1.7}}; // No permite crear el arreglo si su tamaño
											// está dado en terminos de variables

	// TEnemos asignada la memoria para a, falta inicializarla con valires,
	// usemos los de z
	for (int i = 0; i < filas; i++){
		for (int j = 0; j<columnas; j++){
			a[i][j] = matriz_estatica[i][j];
			printf("%f\n", a[i][j]);
		}
	}

	// Definimos el vector b
	int b_size = 4;
	float* b = malloc(b_size * sizeof(float));

	// Limpiamos la memoria usada con malloc
	}
}
