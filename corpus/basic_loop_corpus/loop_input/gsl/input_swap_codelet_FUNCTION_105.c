#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t nz;
int *Ai;
int *ATp;
size_t j;

void init_vars() {
    nz = 64 * 1024 * 1024 / sizeof(int);  // ~256MB of input data (two int arrays)
    
    Ai = (int*)calloc(nz, sizeof(int));
    ATp = (int*)calloc(nz, sizeof(int));

    if (!Ai || !ATp) {
        exit(1);
    }

    for (size_t i = 0; i < nz; ++i) {
        Ai[i] = rand() % nz;
    }
}