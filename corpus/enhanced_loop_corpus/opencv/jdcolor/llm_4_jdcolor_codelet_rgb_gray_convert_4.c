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
        if (inptr0[col] == 0 && inptr1[col] == 0 && inptr2[col] == 0) {
            outptr[col] = 0;
            continue;
        }
        y = Rytab[((int)(inptr0[col]))];
        y += Gytab[((int)(inptr1[col]))];
        y += Bytab[((int)(inptr2[col]))];
        outptr[col] = (JSAMPLE)(y >> 16);
    }
}
