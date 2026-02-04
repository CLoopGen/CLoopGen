#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int N;
int *dindex;

void init_vars() {
    N = 134217728;  // Approximately 512MB of data (134M integers), adjust for ~0.01s runtime
    dindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!dindex) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        dindex[j] = 0;
    }
}