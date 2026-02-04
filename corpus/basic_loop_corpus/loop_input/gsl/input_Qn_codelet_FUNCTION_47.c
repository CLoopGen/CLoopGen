#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 10000;
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
        left[idx] = 0;
        right[idx] = 20;
    }
    i = 0;
    j = 0;
}