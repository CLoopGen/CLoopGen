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
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        y = 0;
        INT32 index0 = 255 - ((int)(inptr0[col]));
        INT32 index1 = 255 - ((int)(inptr1[col]));
        INT32 index2 = 255 - ((int)(inptr2[col]));

        if (index0 >= 0) y += Rytab[index0];
        if (index1 >= 0) y += Gytab[index1];
        if (index2 >= 0) y += Bytab[index2];

        outptr[0] = (JSAMPLE)(y >> 16);
        outptr[1] = inptr3[col];
        outptr += 2;
    }
}
