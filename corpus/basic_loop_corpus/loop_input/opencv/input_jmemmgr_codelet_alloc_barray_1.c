#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int JDIMENSION;
typedef short JCOEF;
typedef JCOEF JBLOCK[64];
typedef JBLOCK* JBLOCKROW;
typedef JBLOCKROW* JBLOCKARRAY;

JDIMENSION blocksperrow = 2048;
JDIMENSION rowsperchunk = 8192;
JDIMENSION currow = 0;
JDIMENSION i;

JBLOCKARRAY result;
JBLOCKROW workspace;

void init_vars() {
    result = (JBLOCKARRAY)aligned_alloc(64, sizeof(JBLOCKROW) * (rowsperchunk + 1));
    workspace = (JBLOCKROW)aligned_alloc(64, sizeof(JBLOCK) * blocksperrow * (rowsperchunk + 1));
}