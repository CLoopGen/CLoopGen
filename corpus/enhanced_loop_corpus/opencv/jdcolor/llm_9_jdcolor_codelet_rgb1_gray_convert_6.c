#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
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
    JDIMENSION col;
    for (col = 0; col < num_cols; col++) {
        r = ((int)(inptr0[col])) >> 2;
        g = ((int)(inptr1[col])) >> 2;
        b = ((int)(inptr2[col])) >> 2;

        INT32 temp_rg = (r + g - 32) & 255;
        INT32 temp_bg = (b + g - 32) & 255;

        y = (Rytab[temp_rg] + Gytab[g] + Bytab[temp_bg] + 0x4000) >> 15;
        outptr[col] = (JSAMPLE)(y & 0xFF);
    }
}
