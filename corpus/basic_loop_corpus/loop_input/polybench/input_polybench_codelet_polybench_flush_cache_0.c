#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

int cs;
double *flush;
int i;
double tmp;

void init_vars() {
    cs = 16777216; // 128 MB of double data (16M elements)
    flush = (double *)aligned_alloc(32, cs * sizeof(double));
    if (!flush) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < cs; j++) {
        flush[j] = (double)(j % 1000) + 0.5;
    }

    tmp = 0.0;
    i = 0;
}