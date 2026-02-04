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
    JDIMENSION temp_currow = currow;
    for (i = rowsperchunk; i > 0; i--) {
        result[temp_currow] = workspace;
        temp_currow++;
        workspace += samplesperrow;
    }
    currow = temp_currow;
}
