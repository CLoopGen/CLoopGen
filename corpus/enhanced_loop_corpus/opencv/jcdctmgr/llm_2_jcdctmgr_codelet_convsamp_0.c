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
    for (elemr = 0; elemr < 8; elemr++) {
        elemptr = sample_data[elemr] + start_col;
        JSAMPLE temp[8];
        for (int i = 0; i < 8; i++) {
            temp[i] = elemptr[i];
        }
        *workspaceptr++ = temp[0] - 128;
        *workspaceptr++ = temp[1] - 128;
        *workspaceptr++ = temp[2] - 128;
        *workspaceptr++ = temp[3] - 128;
        *workspaceptr++ = temp[4] - 128;
        *workspaceptr++ = temp[5] - 128;
        *workspaceptr++ = temp[6] - 128;
        *workspaceptr++ = temp[7] - 128;
    }
}
