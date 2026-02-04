#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 1 << 20;
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

    for (int idx = 1; idx < ni; ++idx) {
        left[idx] = rand() % (1 << 10);
        right[idx] = left[idx] + rand() % (1 << 8);
    }

    i = 0;
    j = 0;
    jh = 0;
}