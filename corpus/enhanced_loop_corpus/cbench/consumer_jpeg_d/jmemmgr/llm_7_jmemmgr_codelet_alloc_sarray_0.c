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
    JDIMENSION idx = currow + rowsperchunk - 1;
    for (i = rowsperchunk; i > 0; i--) {
        result[idx] = workspace;
        idx--;
        workspace += samplesperrow;
    }
    currow += rowsperchunk;
}
