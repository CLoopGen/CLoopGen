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
        if (elemr % 2 == 0) {
            *workspaceptr++ = (*elemptr++) - 128;
            *workspaceptr++ = (*elemptr++) - 128;
            *workspaceptr++ = (*elemptr++) - 128;
            *workspaceptr++ = (*elemptr++) - 128;
        }
        *workspaceptr++ = (*elemptr++) - 128;
        *workspaceptr++ = (*elemptr++) - 128;
        *workspaceptr++ = (*elemptr++) - 128;
        *workspaceptr++ = (*elemptr++) - 128;
    }
}
