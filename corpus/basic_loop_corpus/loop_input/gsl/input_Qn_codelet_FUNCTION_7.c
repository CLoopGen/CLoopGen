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
    left = (int*)aligned_alloc(32, ni * sizeof(int));
    right = (int*)aligned_alloc(32, ni * sizeof(int));

    for (int idx = 0; idx < ni; ++idx) {
        int l = rand() % 10;
        int r = l + rand() % 20;
        left[idx] = l;
        right[idx] = r;
    }

    i = 0;
    j = 0;
}