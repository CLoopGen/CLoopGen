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
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            y = Rytab[((int)(inptr0[col]))] + Gytab[((int)(inptr1[col]))] + Bytab[((int)(inptr2[col]))];
            outptr[col] = (JSAMPLE)(y >> 16);
            y = Rytab[((int)(inptr0[col + 1]))] + Gytab[((int)(inptr1[col + 1]))] + Bytab[((int)(inptr2[col + 1]))];
            outptr[col + 1] = (JSAMPLE)(y >> 16);
        } else {
            y = Rytab[((int)(inptr0[col]))] + Gytab[((int)(inptr1[col]))] + Bytab[((int)(inptr2[col]))];
            outptr[col] = (JSAMPLE)(y >> 16);
        }
    }
}
