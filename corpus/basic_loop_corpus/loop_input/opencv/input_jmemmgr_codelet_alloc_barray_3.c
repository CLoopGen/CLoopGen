#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int JDIMENSION;
typedef short JCOEF;
typedef JCOEF JBLOCK[64];
typedef JBLOCK* JBLOCKROW;
typedef JBLOCKROW* JBLOCKARRAY;

JDIMENSION blocksperrow = 1024;
JDIMENSION rowsperchunk = 256;
JDIMENSION currow = 0;
JDIMENSION i;

JBLOCK* workspace;
JBLOCKARRAY result;

void init_vars() {
    workspace = (JBLOCK*)aligned_alloc(64, blocksperrow * rowsperchunk * sizeof(JBLOCK));
    result = (JBLOCKARRAY)aligned_alloc(64, rowsperchunk * sizeof(JBLOCKROW));

    if (!workspace || !result) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (JDIMENSION r = 0; r < rowsperchunk; r++) {
        for (JDIMENSION b = 0; b < blocksperrow; b++) {
            JBLOCK* block = &workspace[r * blocksperrow + b];
            for (int k = 0; k < 64; k++) {
                (*block)[k] = (JCOEF)(k + r + b);
            }
        }
    }

    currow = 0;
}