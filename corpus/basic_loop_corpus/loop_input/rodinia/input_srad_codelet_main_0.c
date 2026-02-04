#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int Nr;
int *iN;
int *iS;
long i;

void init_vars() {
    Nr = 32000000; // Approximately 128MB of data (32M * 4 bytes per int * 2 arrays)

    iN = (int*)aligned_alloc(32, Nr * sizeof(int));
    iS = (int*)aligned_alloc(32, Nr * sizeof(int));

    if (!iN || !iS) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < Nr; j++) {
        iN[j] = 0;
        iS[j] = 0;
    }
}