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
    JBLOCKROW local_workspace = workspace;
    JDIMENSION local_currow = currow;
    for (i = rowsperchunk; i > 0; i--) {
        result[local_currow++] = local_workspace;
        local_workspace += blocksperrow;
    }
    workspace = local_workspace;
    currow = local_currow;
}
