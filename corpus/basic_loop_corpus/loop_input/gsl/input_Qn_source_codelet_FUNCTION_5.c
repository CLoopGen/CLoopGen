#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

void init_vars() {
    ni = 65536; // Size to target ~0.01s runtime on modern CPU (approx 256KB of data)

    p = (int*)aligned_alloc(32, ni * sizeof(int));
    right = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!p || !right) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        p[j] = rand();
    }
}