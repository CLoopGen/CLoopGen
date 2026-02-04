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
    JDIMENSION col1, col2;
    for (col1 = 0; col1 < num_cols; col1++) {
        for (col2 = 0; col2 < 1; col2++) {
            y = Rytab[((int)(inptr0[col1]))];
            y += Gytab[((int)(inptr1[col1]))];
            y += Bytab[((int)(inptr2[col1]))];
            outptr[col1] = (JSAMPLE)(y >> 16);
        }
    }
}
