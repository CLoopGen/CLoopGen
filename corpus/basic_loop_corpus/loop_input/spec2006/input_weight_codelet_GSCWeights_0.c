#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int nseq;
float *lwt;
float *rwt;
int i;

void init_vars() {
    nseq = 1 << 24;  // 16 million elements, ~64 MB per array (total ~128 MB), adjust for ~0.01 sec on modern CPU
    lwt = (float *)aligned_alloc(32, nseq * sizeof(float));
    rwt = (float *)aligned_alloc(32, nseq * sizeof(float));
    if (!lwt || !rwt) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    memset(lwt, 0, nseq * sizeof(float));
    memset(rwt, 0, nseq * sizeof(float));
}