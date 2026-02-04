#include <stdio.h>

#include <inttypes.h>

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
    JDIMENSION j;
    JSAMPROW temp_workspace = workspace;
    for (j = 0; j < rowsperchunk; j++) {
        result[currow + j] = temp_workspace;
        temp_workspace += samplesperrow;
    }
    currow += rowsperchunk;
    workspace = temp_workspace;
}
