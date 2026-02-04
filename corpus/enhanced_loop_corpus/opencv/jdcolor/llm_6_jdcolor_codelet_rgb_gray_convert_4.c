#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern INT32 y;
extern INT32 *Rytab;
extern INT32 *Gytab;
extern INT32 *Bytab;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        temp_r = Rytab[((int)(inptr0[col]))];
        temp_g = Gytab[((int)(inptr1[col]))];
        temp_b = Bytab[((int)(inptr2[col]))];
        y = temp_r + temp_g + temp_b;
        outptr[col] = (JSAMPLE)(y >> 16);
    }
}
