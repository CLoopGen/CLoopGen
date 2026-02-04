#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

void init_vars() {
    ni = 1 << 20; // 1 million elements, approximately 4MB per array

    p = (int*)aligned_alloc(32, ni * sizeof(int));
    right = (int*)aligned_alloc(32, ni * sizeof(int));

    for (int j = 0; j < ni; ++j) {
        p[j] = rand();
    }
}