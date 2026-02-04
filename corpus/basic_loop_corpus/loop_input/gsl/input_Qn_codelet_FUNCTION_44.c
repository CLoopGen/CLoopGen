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
    ni = 32000000; // Approximately 128MB of data (32M ints * 4 bytes * 2 arrays)

    p = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    for (int j = 0; j < ni; ++j) {
        p[j] = j % 65536;
        q[j] = (j + 1) % 65536;
    }

    sump = 0;
    sumq = 0;
    i = 0;
}