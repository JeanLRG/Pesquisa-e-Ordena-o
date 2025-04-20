#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcsSort.h"



void quick_sort(int v[], int inicio, int fim) {
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2];
    int temp;

    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    if (inicio < j)
        quick_sort(v, inicio, j);
    if (i < fim)
        quick_sort(v, i, fim);
}

void quick_sort_adapter(int *v, int n) {
    quick_sort(v, 0, n - 1);
}