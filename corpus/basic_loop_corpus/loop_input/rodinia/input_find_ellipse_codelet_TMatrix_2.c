#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int N;
int *aindex;
int i;

void init_vars() {
    N = 67108864; // Approximately 256MB: 67M elements * sizeof(int) = 256MB
    aindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!aindex) {
        exit(1);
    }
    for (unsigned int j = 0; j < N; j++) {
        aindex[j] = 0;
    }
}