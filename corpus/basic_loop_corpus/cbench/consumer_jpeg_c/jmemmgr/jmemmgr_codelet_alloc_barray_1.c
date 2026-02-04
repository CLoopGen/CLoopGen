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
for (i = rowsperchunk; i > 0; i--) {
    result[currow++] = workspace;
    workspace += blocksperrow;
}

}
