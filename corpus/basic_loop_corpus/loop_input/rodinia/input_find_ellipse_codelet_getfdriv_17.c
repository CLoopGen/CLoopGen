#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec runtime
int *dindex;
int i;

void init_vars() {
    dindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!dindex) {
        exit(1);
    }
}