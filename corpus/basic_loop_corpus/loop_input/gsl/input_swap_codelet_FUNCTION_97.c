#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t nz;
int *Ai;
int *ATp;
size_t j;

void init_vars() {
    nz = 64 * 1024 * 1024 / sizeof(int);  // Aim for ~64MB of data

    Ai = (int*)malloc(nz * sizeof(int));
    ATp = (int*)malloc(nz * sizeof(int));

    for (size_t i = 0; i < nz; ++i) {
        Ai[i] = rand() % nz;
        ATp[i] = 0;
    }
}