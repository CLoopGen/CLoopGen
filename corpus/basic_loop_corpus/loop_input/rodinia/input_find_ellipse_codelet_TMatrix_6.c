#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int N;
int *cindex;
int i;

void init_vars() {
    N = 134217728; // 128MB of int data (134217728 elements * 4 bytes = 512MB), ensures ~0.01s runtime on modern CPUs
    cindex = (int*)aligned_alloc(64, N * sizeof(int));
    if (!cindex) {
        exit(1);
    }
    for (i = 0; i < N; i++) {
        cindex[i] = 0;
    }
}