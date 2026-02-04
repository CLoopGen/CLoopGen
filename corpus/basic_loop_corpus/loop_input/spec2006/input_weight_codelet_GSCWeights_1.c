#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int nseq;
float *wgt;
float *fwt;
int i;

void init_vars() {
    nseq = 64 * 1024 * 1024 / sizeof(float);  // ~256 MB total for two arrays
    wgt = (float*)malloc(nseq * sizeof(float));
    fwt = (float*)malloc(nseq * sizeof(float));

    if (!wgt || !fwt) {
        exit(1);
    }

    for (int j = 0; j < nseq; j++) {
        fwt[j] = (float)(j % 1000) + 0.5f;
    }

    i = 0;
}