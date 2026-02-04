#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int N = 65536 * 4; // ~256MB of data: 65536*4 = 262144 elements
int *aindex;

void init_vars() {
    aindex = (int*)aligned_alloc(64, N * sizeof(int));
    if (!aindex) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        aindex[j] = 0;
    }
}