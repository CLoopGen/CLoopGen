#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int JDIMENSION;

typedef short JCOEF;

typedef JCOEF JBLOCK[64];

typedef JBLOCK *JBLOCKROW;

typedef JBLOCKROW *JBLOCKARRAY;

extern JDIMENSION blocksperrow;
extern JBLOCKARRAY result;
extern JBLOCKROW workspace;
extern JDIMENSION rowsperchunk;
extern JDIMENSION currow;
extern JDIMENSION i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    JDIMENSION idx = currow;
    JBLOCKROW ws = workspace;
    JBLOCKROW *res = &result[idx];
    for (i = rowsperchunk; i > 1; i -= 2) {
        res[0] = ws;
        res[1] = ws + blocksperrow;
        ws += 2 * blocksperrow;
        res += 2;
    }
    if (i > 0) {
        res[0] = ws;
    }
    currow = idx + rowsperchunk;
    workspace = ws;
}
