#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int N;
int *aindex;

void init_vars() {
    N = 67108864; // ~256MB for int array (67M elements * 4 bytes)
    aindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!aindex) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        aindex[j] = 0;
    }
}