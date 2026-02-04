#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni = 10000000; // 10 million elements for ~0.01 sec runtime

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
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = rand() % 1000;
        right[idx] = left[idx] + rand() % 500;
    }

    i = 1;
    j = 0;
    jh = 0;
}