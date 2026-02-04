#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
int *aindex;
int i;

void init_vars() {
    N = 64 * 1024 * 1024; // 64M elements to target ~0.01 sec on modern CPUs
    aindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!aindex) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        aindex[j] = 0;
    }
    i = 0;
}