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
    for (j = 0; j < rowsperchunk; j++) {
        for (i = 1; i > 0; i--) {
            result[currow++] = workspace;
            workspace += samplesperrow;
        }
    }
}
