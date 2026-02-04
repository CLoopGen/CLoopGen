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
    left = (int*)aligned_alloc(64, ni * sizeof(int));
    right = (int*)aligned_alloc(64, ni * sizeof(int));
    weight = (int*)aligned_alloc(64, ni * sizeof(int));

    if (!left || !right || !weight) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand(12345);
    for (int idx = 0; idx < ni; ++idx) {
        int l = rand() % 1000;
        int r = l + rand() % 500; 
        left[idx] = l;
        right[idx] = r;
    }

    memset(weight, 0, ni * sizeof(int));
    i = 1;
    j = 0;
    jh = 0;
}