#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *p;
int *q;
int i;
long sump;
long sumq;

void init_vars() {
    ni = 1 << 24; // Approximately 16.7 million elements for ~0.01 sec on modern CPU
    p = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!p || !q) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        p[j] = j % 256;
        q[j] = (j + 1) % 256;
    }

    sump = 0;
    sumq = 0;
    i = 0;
}