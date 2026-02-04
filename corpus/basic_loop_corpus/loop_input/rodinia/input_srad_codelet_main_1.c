#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Nc;
int *jE;
int *jW;
long j;

void init_vars() {
    Nc = 67108864;  // Approximately 256MB of data (67M elements * 4 bytes per int * 2 arrays)

    jW = (int*)aligned_alloc(32, Nc * sizeof(int));
    jE = (int*)aligned_alloc(32, Nc * sizeof(int));

    if (!jW || !jE) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < Nc; i++) {
        jW[i] = 0;
        jE[i] = 0;
    }
}