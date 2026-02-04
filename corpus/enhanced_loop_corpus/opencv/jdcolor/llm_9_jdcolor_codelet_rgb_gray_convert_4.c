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
    for (col = 0; col < num_cols; col++) {
        INT32 r_val = ((int)(inptr0[col])) * 2;
        INT32 g_val = ((int)(inptr1[col])) * 2;
        INT32 b_val = ((int)(inptr2[col])) * 2;
        y = Rytab[r_val] + Gytab[g_val] + Bytab[b_val];
        y += (Rytab[r_val + 1] + Gytab[g_val + 1] + Bytab[b_val + 1]) >> 1;
        outptr[col] = (JSAMPLE)((y + (1 << 15)) >> 16);
    }
}
