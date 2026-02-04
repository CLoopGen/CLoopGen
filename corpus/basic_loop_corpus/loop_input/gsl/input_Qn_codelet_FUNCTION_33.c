#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni = 10000000; // ~10M elements for ~0.01 sec runtime estimate

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

    if (!left || !right || !weight) {
        exit(1);
    }

    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = rand() % 1000;
        right[idx] = left[idx] + rand() % 500;
    }
}