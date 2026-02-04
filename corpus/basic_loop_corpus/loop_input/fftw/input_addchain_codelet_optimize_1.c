#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int sqcost;
int n;
int *A;
int i;
int k;
int changed;

void init_vars() {
    sqcost = 42;
    n = (1 << 20); // Approximately 4MB of data (1M integers), adjust for ~0.01s runtime
    A = (int*)calloc(n, sizeof(int));
    if (!A) {
        exit(1);
    }
    i = 0;
    k = 0;
    changed = 0;

    // Initialize A with non-zero values to allow meaningful computation
    for (int idx = 0; idx < n; ++idx) {
        A[idx] = rand() % 1000;
    }
}