#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bucket.h"
#include "funcsSort.h"

#define TAM1 100000
#define TAM2 1000000
#define TAM3 10000000

void gerar_vetor(int *v, int n) {
    int i;
    for (i = 0; i < n; i++)
        v[i] = rand() % (n * 2);  
}

void testar_sort(const char *nome, void (*sort_func)(int*, int), int n) {
    int *v = malloc(n * sizeof(int));
    if (!v) {
        printf("Erro ao alocar memória para %d elementos.\n", n);
        return;
    }

    gerar_vetor(v, n);

    clock_t inicio = clock();
    bucket_sort(v, n, sort_func);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%s - Tamanho: %d - Tempo: %.3f s\n", nome, n, tempo);
    free(v);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    printf("Testando bucket + Heap\n");
    testar_sort("Bucket + Heap", heap_sort, TAM1);
    testar_sort("Bucket + Heap", heap_sort, TAM2);
    testar_sort("Bucket + Heap", heap_sort, TAM3);

    printf("\nTestando Bucket + Quick\n");
    testar_sort("Bucket + Quick", quick_sort_adapter, TAM1);
    testar_sort("Bucket + Quick", quick_sort_adapter, TAM2);
    testar_sort("Bucket + Quick", quick_sort_adapter, TAM3);

    printf("\nTestando Bucket + Merge\n");
    testar_sort("Bucket + Merge", merge_sort_adaptado, TAM1);
    testar_sort("Bucket + Merge", merge_sort_adaptado, TAM2);
    testar_sort("Bucket + Merge", merge_sort_adaptado, TAM3);

    if (argc > 1) {
        int tamanho_personalizado = atoi(argv[1]);
        if (tamanho_personalizado > 0) {
            printf("\nTestando com tamanho personalizado: %d\n", tamanho_personalizado);
            testar_sort("Bucket + Heap", heap_sort, tamanho_personalizado);
            testar_sort("Bucket + Quick", quick_sort_adapter, tamanho_personalizado);
            testar_sort("Bucket + Merge", merge_sort_adaptado, tamanho_personalizado);
        } else {
            printf("\nTamanho inválido fornecido: %s\n", argv[1]);
        }
    }

    return 0;
}
