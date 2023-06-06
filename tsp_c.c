#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_CIUDADES 5

// Matriz de distancias entre ciudades
int matrizDistancias[NUM_CIUDADES][NUM_CIUDADES] = {
    {0, 2, 9, 10, 15},
    {2, 0, 6, 4, 11},
    {9, 6, 0, 7, 12},
    {10, 4, 7, 0, 8},
    {15, 11, 12, 8, 0}
};

// Función para encontrar el siguiente vecino más cercano
int encontrarVecinoMasCercano(int ciudadActual, int visitado[]) {
    int distanciaMinima = INT_MAX;
    int ciudadVecina = -1;
    
    for (int i = 0; i < NUM_CIUDADES; i++) {
        if (!visitado[i] && matrizDistancias[ciudadActual][i] < distanciaMinima) {
            distanciaMinima = matrizDistancias[ciudadActual][i];
            ciudadVecina = i;
        }
    }
    
    return ciudadVecina;
}

// Función para resolver el TSP utilizando el algoritmo del vecino más cercano
void resolverTSP() {
    int visitado[NUM_CIUDADES] = {0}; // Arreglo para almacenar las ciudades visitadas
    int ciudadInicial = 0; // Seleccionamos la primera ciudad como punto de partida
    int ciudadActual = ciudadInicial;
    int contador = 1; // Contador para llevar la cuenta de las ciudades visitadas
    int distanciaTotal = 0; // Distancia total recorrida
    
    printf("Recorrido del TSP: ");
    printf("%d ", ciudadInicial);
    visitado[ciudadInicial] = 1;
    
    for (contador = 1; contador < NUM_CIUDADES; contador++) {
        int ciudadVecina = encontrarVecinoMasCercano(ciudadActual, visitado);
        
        printf("%d ", ciudadVecina);
        visitado[ciudadVecina] = 1;
        distanciaTotal += matrizDistancias[ciudadActual][ciudadVecina];
        
        ciudadActual = ciudadVecina;
    }
    
    distanciaTotal += matrizDistancias[ciudadActual][ciudadInicial];
    
    printf("\nDistancia total: %d\n", distanciaTotal);
}

int main() {
    resolverTSP();
    return 0;
}
