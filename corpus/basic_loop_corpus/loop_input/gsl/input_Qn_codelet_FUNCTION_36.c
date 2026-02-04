#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni;
int *p;
int *q;
int i;
long sump;
long sumq;

void init_vars() {
    ni = 64 * 1024 * 1024 / sizeof(int);  // ~256MB total data (128MB per array)
    
    p = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));
    
    if (!p || !q) {
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < ni; ++idx) {
        p[idx] = idx % 256;
        q[idx] = (idx + 1) % 256;
    }

    sump = 0;
    sumq = 0;
    i = 0;
}