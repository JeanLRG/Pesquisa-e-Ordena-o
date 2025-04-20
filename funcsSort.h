#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>


void mostra(int *vetor, int tam);
double difTempo(struct timespec t0, struct timespec t1);
int *embaralha(int *vetor, int tam);

#ifndef FUNCS_SORT_H
#define FUNCS_SORT_H

void insertion_sort(int *v, int n);
void selection_sort(int *v, int n);
void quick_sort(int v[], int inicio, int fim);
void quick_sort_adapter(int *v, int n);
void heap_sort(int *v, int n);
void bubble_sort(int *v, int n);
void selection_sort(int *v, int n);
void mostra (int *vet, int n);
void diftempo (clock_t start, clock_t end);

#endif