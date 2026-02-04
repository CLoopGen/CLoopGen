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
        JSAMPLE val0 = *elemptr++;
        JSAMPLE val1 = *elemptr++;
        JSAMPLE val2 = *elemptr++;
        JSAMPLE val3 = *elemptr++;
        JSAMPLE val4 = *elemptr++;
        JSAMPLE val5 = *elemptr++;
        JSAMPLE val6 = *elemptr++;
        JSAMPLE val7 = *elemptr++;
        *workspaceptr++ = val0 - 128;
        *workspaceptr++ = val1 - 128;
        *workspaceptr++ = val2 - 128;
        *workspaceptr++ = val3 - 128;
        *workspaceptr++ = val4 - 128;
        *workspaceptr++ = val5 - 128;
        *workspaceptr++ = val6 - 128;
        *workspaceptr++ = val7 - 128;
    }
}
