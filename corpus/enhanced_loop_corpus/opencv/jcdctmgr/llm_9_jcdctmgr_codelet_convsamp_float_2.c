#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern float *workspaceptr;
extern JSAMPROW elemptr;
extern int elemr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (elemr = 0; elemr < 4; elemr++) {
    elemptr = sample_data[elemr] + start_col;
    for (int j = 0; j < 16; j += 2) {
        *workspaceptr++ = (float)((elemptr[j] - 128) * 1.5f);
        *workspaceptr++ = (float)((elemptr[j+1] - 128) * 1.5f);
    }
}
}
