#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 2; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    INT32 a0 = (int)elemptr[0];
    INT32 a1 = (int)elemptr[1];
    INT32 a2 = (int)elemptr[2];
    INT32 a3 = (int)elemptr[3];
    a0 -= 128; a1 -= 128; a2 -= 128; a3 -= 128;
    dataptr[0] = (DCTELEM)((a0 + a3));
    dataptr[1] = (DCTELEM)((a1 + a2));
    dataptr[2] = (DCTELEM)((a1 - a2));
    dataptr[3] = (DCTELEM)((a0 - a3));
    dataptr += 8;
    
    elemptr = sample_data[ctr + 2] + start_col;
    a0 = (int)elemptr[0]; a1 = (int)elemptr[1]; a2 = (int)elemptr[2]; a3 = (int)elemptr[3];
    a0 -= 128; a1 -= 128; a2 -= 128; a3 -= 128;
    dataptr[0] = (DCTELEM)((a0 + a3));
    dataptr[1] = (DCTELEM)((a1 + a2));
    dataptr[2] = (DCTELEM)((a1 - a2));
    dataptr[3] = (DCTELEM)((a0 - a3));
    dataptr += 8;
}
}
