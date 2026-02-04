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
    for (elemr = 0; elemr < 8; elemr++) {
        elemptr = sample_data[elemr] + start_col;
        int offset = 0;
        if (elemr >= 4) {
            // Only process the first four elements for later rows
            for (; offset < 4; offset++) {
                *workspaceptr++ = (float)((elemptr[offset]) - 128);
            }
        } else {
            // Full write for first four rows
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
