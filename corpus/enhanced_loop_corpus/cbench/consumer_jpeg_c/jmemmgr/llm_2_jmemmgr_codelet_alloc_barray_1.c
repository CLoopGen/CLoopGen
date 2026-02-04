#include <stdio.h>

#include <inttypes.h>

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
    // Variant 1: Consecutive memory access with reversed iteration using index arithmetic
    JDIMENSION idx;
    for (idx = 0; idx < rowsperchunk; idx++) {
        result[currow + idx] = workspace + idx * blocksperrow;
    }
    currow += rowsperchunk;
}
