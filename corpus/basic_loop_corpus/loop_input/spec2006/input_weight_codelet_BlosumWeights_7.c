#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int nseq;
float *wgt;
int *c;
int *nmem;
int i;

void init_vars() {
    nseq = 64 * 1024 * 1024 / sizeof(float);  // ~64M elements for ~100-200MB total data
    wgt = (float*)malloc(nseq * sizeof(float));
    c = (int*)malloc(nseq * sizeof(int));
    nmem = (int*)malloc((nseq + 1) * sizeof(int));

    if (!wgt || !c || !nmem) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (i = 0; i < nseq; i++) {
        c[i] = rand() % nseq;  // ensure c[i] is within [0, nseq-1]
    }
    for (i = 0; i < nseq + 1; i++) {
        nmem[i] = rand() % 100 + 1;  // positive values to avoid division by zero
    }
}