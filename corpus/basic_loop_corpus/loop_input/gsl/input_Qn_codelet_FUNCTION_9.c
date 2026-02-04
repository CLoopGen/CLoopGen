#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 10000000;

int *left;
int *right;
int *weight;
int i;
int j;
int jh;

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

    i = 0;
    j = 0;
    jh = 0;
}