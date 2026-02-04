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
    // Variant 2: Consecutive Pointer-Based Access (use pointer arithmetic for sequential access)
    JSAMPROW inptr0_end = inptr0 + num_cols;
    JSAMPROW p0 = inptr0;
    JSAMPROW p1 = inptr1;
    JSAMPROW p2 = inptr2;
    JSAMPROW out = outptr;

    while (p0 < inptr0_end) {
        y = Rytab[*p0];
        y += Gytab[*p1];
        y += Bytab[*p2];
        *out = (JSAMPLE)(y >> 16);
        p0++;
        p1++;
        p2++;
        out++;
    }
}
