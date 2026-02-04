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
    float *wsptr_base = workspaceptr;
    for (elemr = 0; elemr < 8; elemr++) {
        JSAMPROW elemptr = sample_data[elemr] + start_col;
        float offset_val = -128.0f;
        float base0 = (float)elemptr[0] + offset_val;
        float base1 = (float)elemptr[1] + offset_val;
        float base2 = (float)elemptr[2] + offset_val;
        float base3 = (float)elemptr[3] + offset_val;
        float base4 = (float)elemptr[4] + offset_val;
        float base5 = (float)elemptr[5] + offset_val;
        float base6 = (float)elemptr[6] + offset_val;
        float base7 = (float)elemptr[7] + offset_val;

        wsptr_base[elemr * 8 + 0] = base0;
        wsptr_base[elemr * 8 + 1] = base1;
        wsptr_base[elemr * 8 + 2] = base2;
        wsptr_base[elemr * 8 + 3] = base3;
        wsptr_base[elemr * 8 + 4] = base4;
        wsptr_base[elemr * 8 + 5] = base5;
        wsptr_base[elemr * 8 + 6] = base6;
        wsptr_base[elemr * 8 + 7] = base7;
    }
    workspaceptr += 64;
}
