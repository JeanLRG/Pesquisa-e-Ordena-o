#include <stdio.h>
#include <stdlib.h>
#include "bucket.h"
#include "funcsSort.h"


#define BUCKET_SIZE 1000

typedef struct {
    int *valores;
    int tamanho;
    int capacidade;
} Bucket;

void inserir_bucket(Bucket *bucket, int valor) {
    if (bucket->tamanho == bucket->capacidade) {
        bucket->capacidade *= 2;
        bucket->valores = realloc(bucket->valores, bucket->capacidade * sizeof(int));
    }
    bucket->valores[bucket->tamanho++] = valor;
}

void bucket_sort(int *vetor, int n, void (*sort_func)(int*, int)) {
    int i, bucket_count = n / BUCKET_SIZE + 1;
    Bucket *buckets = malloc(bucket_count * sizeof(Bucket));

    for (i = 0; i < bucket_count; i++) {
        buckets[i].valores = malloc(BUCKET_SIZE * sizeof(int));
        buckets[i].tamanho = 0;
        buckets[i].capacidade = BUCKET_SIZE;
    }

    for (i = 0; i < n; i++) {
        int index = vetor[i] / BUCKET_SIZE;
        if (index >= bucket_count) index = bucket_count - 1;
        inserir_bucket(&buckets[index], vetor[i]);
    }

    int k = 0;
    for (i = 0; i < bucket_count; i++) {
        if (buckets[i].tamanho > 0) {
            sort_func(buckets[i].valores, buckets[i].tamanho);
            int j;
            for (j = 0; j < buckets[i].tamanho; j++) {
                vetor[k++] = buckets[i].valores[j];
            }
        }
        free(buckets[i].valores);
    }

    free(buckets);
}
