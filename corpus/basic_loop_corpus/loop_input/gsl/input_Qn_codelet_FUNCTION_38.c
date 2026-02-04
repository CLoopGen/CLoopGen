#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    ni = 65536; // Size chosen to ensure ~0.01s runtime (approx 256KB of data)

    left = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    for (int j = 0; j < ni; ++j) {
        q[j] = rand();
    }

    i = 0;
}