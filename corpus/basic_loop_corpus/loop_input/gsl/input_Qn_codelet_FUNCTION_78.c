#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 65536;
int *left;
int *q;
int i;

void init_vars() {
    left = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    for (i = 0; i < ni; ++i) {
        q[i] = i * 3 + 1;
        left[i] = 0;
    }
}