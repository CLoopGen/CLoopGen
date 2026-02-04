#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 1000000;
int *left;
int *right;
int i;
int j;

void init_vars() {
    left = (int*)calloc(ni, sizeof(int));
    right = (int*)calloc(ni, sizeof(int));
    if (!left || !right) {
        exit(1);
    }
    for (int idx = 1; idx < ni; ++idx) {
        int range = rand() % 20 + 1;
        left[idx] = idx * 2;
        right[idx] = left[idx] + range - 1;
    }
    i = 0;
    j = 0;
}