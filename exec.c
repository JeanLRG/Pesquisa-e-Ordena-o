#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcsSort.h"


#define TAMANHOS 3

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void insertion_sort(int arr[], int n) {
    int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    int i, j, k;
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L); free(R);
}


void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void sort_bucket(int *bucket, int size, int metodo) {
    if (metodo == 1) insertion_sort(bucket, size);
    else if (metodo == 2) merge_sort(bucket, 0, size - 1);
    else if (metodo == 3) qsort(bucket, size, sizeof(int), compare);
}

void bucket_sort(int *arr, int n, int metodo) {
    int num_buckets = 100000;
    int max = arr[0];
    int i, j, idx;

    for (i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    int **buckets = malloc(num_buckets * sizeof(int *));
    int *bucket_sizes = calloc(num_buckets, sizeof(int));
    int *bucket_cap = malloc(num_buckets * sizeof(int));

    for (i = 0; i < num_buckets; i++) {
        bucket_cap[i] = 10;
        buckets[i] = malloc(bucket_cap[i] * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int index = (arr[i] * num_buckets) / (max + 1);
        if (bucket_sizes[index] == bucket_cap[index]) {
            bucket_cap[index] *= 2;
            buckets[index] = realloc(buckets[index], bucket_cap[index] * sizeof(int));
        }
        buckets[index][bucket_sizes[index]++] = arr[i];
    }

    idx = 0;
    for (i = 0; i < num_buckets; i++) {
        sort_bucket(buckets[i], bucket_sizes[i], metodo);
        for (j = 0; j < bucket_sizes[i]; j++)
            arr[idx++] = buckets[i][j];
        free(buckets[i]);
    }

    free(buckets);
    free(bucket_sizes);
    free(bucket_cap);
}


void testar_bucket_sort(int tamanho, int metodo) {
    const char *nome_metodo = 
        (metodo == 1) ? "Insertion Sort" : 
        (metodo == 2) ? "Merge Sort" : 
        (metodo == 3) ? "Quick Sort (qsort)" : 
        "Desconhecido";

    int *arr = malloc(tamanho * sizeof(int));
    if (!arr) {
        printf("Erro ao alocar memória para %d elementos\n", tamanho);
        return;
    }

    srand(42); 
    int i;
    for ( i = 0; i < tamanho; i++) {
        arr[i] = rand();
    }

    printf("Executando: %s | Tamanho: %d...\n", nome_metodo, tamanho);

    clock_t ini = clock();
    bucket_sort(arr, tamanho, metodo);
    clock_t fim = clock();

    double tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("Finalizado: %s | Tamanho: %d | Tempo: %.3f segundos\n\n", nome_metodo, tamanho, tempo);

    free(arr);
}

int main() {
    int tamanhos[] = {100000, 1000000, 100000000}; 
    int i;
    for ( i = 0; i < TAMANHOS; i++) {
        int tamanho = tamanhos[i];
        int metodo;
        for ( metodo = 1; metodo <= 3; metodo++) {
            testar_bucket_sort(tamanho, metodo);
        }
    }

    return 0;
}
