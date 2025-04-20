#include <stdio.h>
#include <stdlib.h>
#include "funcsSort.h"


void imprimeVet(int *vet, int tam){
  int i;
  for(i=0; i<tam; i++)
    printf("%d\n",vet[i]);
  return;
}

/* retorna 0 se nao ordenado e 1 se ordenado */
int estaOrdenado(int *vet, int tam){
  int i;
  for(i=0; i<tam-1; i++)
    if(vet[i] > vet[i+1])
      return 0;
  return 1;
}


int selectSort(int *vet, int tam){
  int i, j, menor, aux;
  for(i=0; i< tam-1; i++){
    for(j=i+1, menor = i; j<tam; j++ ){
      if(vet[j] < vet[menor])
        menor = j;
    }
    aux = vet[i];
    vet[i] = vet[menor];
    vet[menor] = aux;
  }
}

int main(int argc, char *argv[]){
  int i, *vet, aux;
  int tam;
  if (argc != 2 ){
    printf("uso: %s <num_elementos_a_ordenar>\n", argv[0]);
    exit(1);
  }
  tam = (int)atoi(argv[1]);
  vet = (int *)malloc(tam * sizeof(int));
  for(i=0; i<tam; i++){
    fscanf(stdin,"%d", &aux);
    vet[i] = aux;
  }
  
  selectSort(vet, tam);
  /* imprimeVet(vet, tam); */
  exit(0);
}

