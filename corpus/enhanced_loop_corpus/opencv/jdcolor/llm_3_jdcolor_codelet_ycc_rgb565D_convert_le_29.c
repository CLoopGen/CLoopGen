#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern int y;
extern int cb;
extern int cr;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern JLONG *Crgtab;
extern JLONG *Cbgtab;
extern JLONG d0;
extern JLONG rgb;
extern unsigned int r;
extern unsigned int g;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
JDIMENSION stride = 2;
for (col = 0; col < (num_cols >> 1); col++) {
    JSAMPROW p0 = inptr0 + (col * stride);
    JSAMPROW p1 = inptr1 + (col * stride);
    JSAMPROW p2 = inptr2 + (col * stride);
    y = *p0;
    cb = *p1;
    cr = *p2;
    r = range_limit[((y + Crrtab[cr]) + ((d0) & 255))];
    g = range_limit[((y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))) + (((d0) & 255) >> 1))];
    b = range_limit[((y + Cbbtab[cb]) + ((d0) & 255))];
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    rgb = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));
    y = *(p0 + 1);
    cb = *(p1 + 1);
    cr = *(p2 + 1);
    r = range_limit[((y + Crrtab[cr]) + ((d0) & 255))];
    g = range_limit[((y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))) + (((d0) & 255) >> 1))];
    b = range_limit[((y + Cbbtab[cb]) + ((d0) & 255))];
    d0 = ((((d0) & 255) << 24) | (((d0) >> 8) & 16777215));
    rgb = ((((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3)) << 16) | rgb);
    ((*(int *)(outptr)) = rgb);
    outptr += 4;
}
}
