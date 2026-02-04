#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    ni = 32000000; // Approximately 128MB of data (32M * 4 bytes per int)

    left = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!left || !q) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        q[j] = j * 2;
        left[j] = 0;
    }
}