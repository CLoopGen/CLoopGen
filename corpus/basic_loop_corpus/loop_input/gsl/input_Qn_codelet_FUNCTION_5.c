#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 65536;
int *right;
int *p;
int i;

void init_vars() {
    right = (int*)aligned_alloc(32, ni * sizeof(int));
    p = (int*)aligned_alloc(32, ni * sizeof(int));

    for (i = 0; i < ni; ++i) {
        p[i] = rand();
    }
}