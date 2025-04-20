#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "funcsSort.h"

int *bubbleSort(int *vetor, int tam){
  int cont, troca, aux;
  do {
    troca = 0;
    for (cont = 0; cont < tam - 1; cont++) {
      if (vetor[cont] > vetor[cont + 1]) {
        aux = vetor[cont];
        vetor[cont] = vetor[cont + 1];
        vetor[cont + 1] = aux;
        troca = 1;
      }
    }
  } while (troca);
  return vetor;
}

int main(int argc, char *argv[]) {
  int i;
  int *vet;
  char linha[16];
  int tamVet;
  clock_t start, end;

  if (argc < 2) {
    printf("Uso: %s <numero de elementos a ordenar>\n", argv[0]);
    exit(0);
  }

  tamVet = atoi(argv[1]);
  vet = (int *) malloc(sizeof(int) * tamVet);

  for (i = 0; i < tamVet; i++) {
    fgets(linha, 16, stdin);
    sscanf(linha, "%d", &vet[i]);
  }

  start = clock();
  bubbleSort(vet, tamVet);
  end = clock();

  printf("Tempo Bubble Sort: %.3f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}
