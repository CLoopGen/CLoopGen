#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 10000000; // Approximately 10M iterations for ~0.01s runtime

int *left;
int *right;
int *weight;
int i = 0;
int j = 0;
int jh = 0;

void init_vars() {
    left = (int*)calloc(ni, sizeof(int));
    right = (int*)calloc(ni, sizeof(int));
    weight = (int*)calloc(ni, sizeof(int));

    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = rand() % 1000;
        right[idx] = left[idx] + rand() % 200; // Ensures right[i] >= left[i] often
    }
}