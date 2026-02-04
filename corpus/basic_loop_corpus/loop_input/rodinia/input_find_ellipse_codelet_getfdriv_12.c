#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
int *aindex;
int i;

void init_vars() {
    N = 64000000; // Approximately 256MB for int array (64M elements * 4 bytes)
    aindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!aindex) {
        exit(1);
    }
    // Ensure initialization of aindex to avoid undefined behavior
    for (int j = 0; j < N; j++) {
        aindex[j] = 0;
    }
}