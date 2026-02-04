#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int JDIMENSION;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

extern JDIMENSION samplesperrow;
extern JSAMPARRAY result;
extern JSAMPROW workspace;
extern JDIMENSION rowsperchunk;
extern JDIMENSION currow;
extern JDIMENSION i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_workspace = workspace;
    JDIMENSION local_currow = currow;
    for (i = rowsperchunk; i > 0; i--) {
        result[local_currow++] = local_workspace;
        local_workspace += samplesperrow;
    }
    currow = local_currow;
    workspace = local_workspace;
}
