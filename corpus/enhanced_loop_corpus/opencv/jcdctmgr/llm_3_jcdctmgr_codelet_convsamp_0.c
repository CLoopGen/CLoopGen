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
    DCTELEM *wp_base = workspaceptr;
    for (elemr = 0; elemr < 8; elemr++) {
        elemptr = sample_data[elemr] + start_col;
        wp_base[elemr + 0*8] = elemptr[0] - 128;
        wp_base[elemr + 1*8] = elemptr[1] - 128;
        wp_base[elemr + 2*8] = elemptr[2] - 128;
        wp_base[elemr + 3*8] = elemptr[3] - 128;
        wp_base[elemr + 4*8] = elemptr[4] - 128;
        wp_base[elemr + 5*8] = elemptr[5] - 128;
        wp_base[elemr + 6*8] = elemptr[6] - 128;
        wp_base[elemr + 7*8] = elemptr[7] - 128;
    }
    workspaceptr += 64;
}
