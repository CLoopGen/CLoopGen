#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 65536;
int *aindex;
int i;

void init_vars() {
    aindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!aindex) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        aindex[j] = 0;
    }
}