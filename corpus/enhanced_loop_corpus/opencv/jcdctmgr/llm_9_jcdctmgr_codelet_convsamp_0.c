#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

typedef JLONG DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern DCTELEM *workspaceptr;
extern JSAMPROW elemptr;
extern int elemr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (elemr = 0; elemr < 4; elemr++) {
    elemptr = sample_data[elemr] + start_col;
    *workspaceptr++ = (elemptr[0] - 128) + (elemptr[1] - 128);
    *workspaceptr++ = (elemptr[2] - 128) + (elemptr[3] - 128);
    *workspaceptr++ = (elemptr[4] - 128) + (elemptr[5] - 128);
    *workspaceptr++ = (elemptr[6] - 128) + (elemptr[7] - 128);
}
}
