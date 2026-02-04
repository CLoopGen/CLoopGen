#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int TotalNumberofBasicUnit;
double *FCBUCFMAD;
double *FCBUPFMAD;
int i;

void init_vars() {
    // Set data size to achieve ~0.01 seconds runtime
    // Assuming modern CPU can handle memory copy at several GB/s, use 64MB of doubles (~512MB/s estimate)
    TotalNumberofBasicUnit = 8 * 1024 * 1024; // 8M elements -> 64 MB (each double is 8 bytes)

    FCBUCFMAD = (double*)aligned_alloc(32, TotalNumberofBasicUnit * sizeof(double));
    FCBUPFMAD = (double*)aligned_alloc(32, TotalNumberofBasicUnit * sizeof(double));

    if (!FCBUCFMAD || !FCBUPFMAD) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < TotalNumberofBasicUnit; j++) {
        FCBUCFMAD[j] = (double)(j % 1000) + 0.5;
    }

    i = 0;
}