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
    left = (int*)malloc(ni * sizeof(int));
    right = (int*)malloc(ni * sizeof(int));

    for (i = 0; i < ni; ++i) {
        left[i] = i;
        right[i] = i + 10;
    }
    i = 0;
    j = 0;
}