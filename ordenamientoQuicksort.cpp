#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#define TAM 50

using namespace std;


void quicksort(int *vector, int inicio, int fin){
	// Funci�n recursiva para hacer el ordenamiento
	int pivot;
	
	if (inicio < fin) {
		pivot = dividir(vector, inicio, fin);
		
		// Ordeno la lista de los menores
		quicksort(vector, inicio, pivot - 1);
		
		// Ordeno la lista de los mayores
		quicksort(vector, pivot + 1, fin);
	}
}


int dividir(int *vector, int inicio, int fin) {
	// Funci�n para dividir el array y hacer los intercambios
	int izq;
	int der;
	int pivot;
	int aux;
	
	pivot= vector[inicio];
	izq=inicio;
	der=fin;
	
	// Mientras no se cruzen los �ndices
	while (izq < der) {
		while (vector[der] > pivot) {
			der--;
		}
		
		while ((izq < der) && (vector[izq] <= pivot)) {
			izq++;
		}
		
		// Si todav�a no se cruzan los indices seguimos intercambiando
		if (izq < der) {
			aux = vector[izq];
			vector[izq] = vector[der];
			vector[der]=aux;
		}
	}
	
	// Los �ndices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
	aux = vector[der];
	vector[der] = vector[inicio];
	vector[inicio] = aux;
	
	// La nueva posici�n del pivot
	return der;
}
