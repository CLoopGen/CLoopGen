#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 100000;

int *left;
int *right;
int i;
int j;

void init_vars() {
    left = (int*)calloc(ni, sizeof(int));
    right = (int*)calloc(ni, sizeof(int));

    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = idx % 50;
        right[idx] = (idx % 50) + 20;
    }

    i = 0;
    j = 0;
}