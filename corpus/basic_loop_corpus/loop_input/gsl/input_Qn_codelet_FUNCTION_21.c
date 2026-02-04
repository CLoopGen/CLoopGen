#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

void init_vars() {
    ni = 65536; // Size to achieve ~0.01s runtime (tuned for typical modern CPU)

    p = (int*)aligned_alloc(32, ni * sizeof(int));
    right = (int*)aligned_alloc(32, ni * sizeof(int));

    for (i = 0; i < ni; ++i) {
        p[i] = rand();
        right[i] = 0;
    }
}