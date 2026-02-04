#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

int nseq;
float **dmx;
float *halfmin;
int idx;
int i;
float min;

void init_vars() {
    nseq = 1024; // Size chosen to achieve ~0.01s runtime

    // Allocate halfmin array
    halfmin = (float*)calloc(nseq, sizeof(float));
    if (!halfmin) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Allocate dmx as a 2D array (nseq x nseq)
    dmx = (float**)malloc(nseq * sizeof(float*));
    if (!dmx) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < nseq; idx++) {
        dmx[idx] = (float*)malloc(nseq * sizeof(float));
        if (!dmx[idx]) {
            fprintf(stderr, "Allocation failed\n");
            exit(1);
        }
    }

    // Initialize dmx with sample values between 0.5 and 2.0
    srand(time(NULL));
    for (int i = 0; i < nseq; i++) {
        for (int j = 0; j < nseq; j++) {
            dmx[i][j] = 0.5f + (rand() / (float)RAND_MAX) * 1.5f;
        }
    }
}