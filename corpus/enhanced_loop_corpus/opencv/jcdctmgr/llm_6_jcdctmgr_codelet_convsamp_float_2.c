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
    float *local_workspace = workspaceptr;
    JSAMPROW local_elemptr;
    for (elemr = 0; elemr < 8; elemr++) {
        local_elemptr = sample_data[elemr] + start_col;
        *local_workspace++ = (float)(local_elemptr[0] - 128);
        *local_workspace++ = (float)(local_elemptr[1] - 128);
        *local_workspace++ = (float)(local_elemptr[2] - 128);
        *local_workspace++ = (float)(local_elemptr[3] - 128);
        *local_workspace++ = (float)(local_elemptr[4] - 128);
        *local_workspace++ = (float)(local_elemptr[5] - 128);
        *local_workspace++ = (float)(local_elemptr[6] - 128);
        *local_workspace++ = (float)(local_elemptr[7] - 128);
    }
    workspaceptr = local_workspace;
}
