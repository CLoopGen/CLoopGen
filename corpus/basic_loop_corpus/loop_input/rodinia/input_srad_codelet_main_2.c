#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long Nr;
int *iN;
int *iS;
long i;

void init_vars() {
    Nr = 67108864; // Approximately 256MB of data (each array is 256MB / 2 = 128MB for int, 67M elements)

    iN = (int*)aligned_alloc(32, Nr * sizeof(int));
    iS = (int*)aligned_alloc(32, Nr * sizeof(int));

    if (!iN || !iS) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (long idx = 0; idx < Nr; idx++) {
        iN[idx] = 0;
        iS[idx] = 0;
    }

    i = 0;
}