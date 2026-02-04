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
    JDIMENSION outer = rowsperchunk / 2;
    JDIMENSION remainder = rowsperchunk % 2;
    for (i = outer; i > 0; i--) {
        result[currow++] = workspace;
        workspace += samplesperrow;
        result[currow++] = workspace;
        workspace += samplesperrow;
    }
    for (i = remainder; i > 0; i--) {
        result[currow++] = workspace;
        workspace += samplesperrow;
    }
}
