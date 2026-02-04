#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni = 10000000; // Approximately 10 million iterations for ~0.01 sec runtime

int *left;
int *right;
int *weight;
int i = 0;
int j = 0;
int jh = 0;

void init_vars() {
    left = (int*)aligned_alloc(32, ni * sizeof(int));
    right = (int*)aligned_alloc(32, ni * sizeof(int));
    weight = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!left || !right || !weight) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand(12345);
    for (int idx = 0; idx < ni; ++idx) {
        int l_val = rand() % 1000;
        int r_val = l_val + rand() % 500; // Ensure right[i] >= left[i] sometimes
        left[idx] = l_val;
        right[idx] = r_val;
    }

    i = 0;
    j = 0;
    jh = 0;

    memset(weight, 0, ni * sizeof(int));
}