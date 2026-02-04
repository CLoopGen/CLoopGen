#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned int JDIMENSION;
typedef short JCOEF;
typedef JCOEF JBLOCK[64];
typedef JBLOCK* JBLOCKROW;
typedef JBLOCKROW* JBLOCKARRAY;

JDIMENSION blocksperrow;
JBLOCKARRAY result;
JBLOCKROW workspace;
JDIMENSION rowsperchunk;
JDIMENSION currow;
JDIMENSION i;

void init_vars() {
    blocksperrow = 64;
    rowsperchunk = 100000;
    currow = 0;

    result = (JBLOCKARRAY)calloc(rowsperchunk, sizeof(JBLOCKROW));
    if (!result) {
        exit(1);
    }

    JCOEF* workspace_base = (JCOEF*)calloc(rowsperchunk * blocksperrow, sizeof(JCOEF));
    if (!workspace_base) {
        exit(1);
    }

    workspace = (JBLOCKROW)workspace_base;
}