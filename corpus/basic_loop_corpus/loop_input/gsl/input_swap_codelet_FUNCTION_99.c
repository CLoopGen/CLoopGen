#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t N = 1 << 20;
int *Ai;
int *Ap;
int *ATi;
int *w;

int p;
size_t j;

void init_vars() {
    Ai = (int*)calloc(N, sizeof(int));
    Ap = (int*)calloc(N + 1, sizeof(int));
    w = (int*)calloc(N, sizeof(int));
    ATi = (int*)calloc(N, sizeof(int));

    for (j = 0; j <= N; ++j) {
        Ap[j] = j;
    }

    for (j = 0; j < N; ++j) {
        Ai[j] = rand() % N;
    }
}