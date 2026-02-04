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
    ni = 1 << 20; // 1 million elements, ~4MB of data per array

    p = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!p || !q) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < ni; ++idx) {
        p[idx] = idx % 65536;
        q[idx] = (idx + 1) % 65536;
    }

    sump = 0;
    sumq = 0;
    i = 0;
}