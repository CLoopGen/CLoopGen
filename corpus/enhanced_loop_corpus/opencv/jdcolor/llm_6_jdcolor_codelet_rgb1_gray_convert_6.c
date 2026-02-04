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
    INT32 temp_y;
    for (col = 0; col < num_cols; col++) {
        r = ((int)(inptr0[col]));
        g = ((int)(inptr1[col]));
        b = ((int)(inptr2[col]));
        temp_y = Rytab[(r + g - 128) & 255];
        temp_y += Gytab[g];
        temp_y += Bytab[(b + g - 128) & 255];
        outptr[col] = (JSAMPLE)(temp_y >> 16);
    }
}
