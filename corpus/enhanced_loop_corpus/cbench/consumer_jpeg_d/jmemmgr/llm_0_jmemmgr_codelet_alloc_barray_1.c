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
    JDIMENSION outer = rowsperchunk / 2;
    JDIMENSION inner;
    for (i = outer; i > 0; i--) {
        inner = 2;
        for (JDIMENSION j = inner; j > 0; j--) {
            result[currow++] = workspace;
            workspace += blocksperrow;
        }
    }
    if (rowsperchunk % 2 != 0) {
        result[currow++] = workspace;
        workspace += blocksperrow;
    }
}
