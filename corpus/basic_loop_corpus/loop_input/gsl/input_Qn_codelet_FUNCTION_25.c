#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni = 10000000; // ~10M elements for ~0.01 sec runtime

int *left;
int *right;
int *weight;
int i;
int j;
int jh;

void init_vars() {
    left = (int*)aligned_alloc(64, ni * sizeof(int));
    right = (int*)aligned_alloc(64, ni * sizeof(int));
    weight = (int*)aligned_alloc(64, ni * sizeof(int));

    if (!left || !right || !weight) {
        exit(1);
    }

    // Initialize arrays to ensure valid memory accesses
    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = rand() % 1000;
        right[idx] = left[idx] + rand() % 200; // Ensure right >= left sometimes
    }

    // Initialize loop counters
    i = 0;
    j = 0;
    jh = 0;
}