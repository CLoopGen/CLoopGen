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
    for (int outer = 0; outer < 2; outer++) {
        for (elemr = 0; elemr < 4; elemr++) {
            int row_index = outer * 4 + elemr;
            elemptr = sample_data[row_index] + start_col;
            *workspaceptr++ = (float)((*elemptr++) - 128);
            *workspaceptr++ = (float)((*elemptr++) - 128);
            *workspaceptr++ = (float)((*elemptr++) - 128);
            *workspaceptr++ = (float)((*elemptr++) - 128);
            *workspaceptr++ = (float)((*elemptr++) - 128);
            *workspaceptr++ = (float)((*elemptr++) - 128);
            *workspaceptr++ = (float)((*elemptr++) - 128);
            *workspaceptr++ = (float)((*elemptr++) - 128);
        }
    }
}
