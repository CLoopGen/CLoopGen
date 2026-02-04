#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long Nc;
int *jE;
int *jW;
long j;

void init_vars() {
    Nc = 67108864; // Approximately 256MB of data (each array is 256MB / 2 ints -> ~67M elements)

    jE = (int*)aligned_alloc(32, Nc * sizeof(int));
    jW = (int*)aligned_alloc(32, Nc * sizeof(int));

    if (!jE || !jW) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (long i = 0; i < Nc; i++) {
        jE[i] = 0;
        jW[i] = 0;
    }
}