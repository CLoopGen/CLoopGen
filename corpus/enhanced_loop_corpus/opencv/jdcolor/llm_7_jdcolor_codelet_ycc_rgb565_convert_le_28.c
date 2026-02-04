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
extern JLONG rgb;
extern unsigned int r;
extern unsigned int g;
extern unsigned int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
JLONG temp_rgb1 = 0, temp_rgb2 = 0;
int y1, y2, cb1, cb2, cr1, cr2;
for (col = 0; col < (num_cols >> 1); col++) {
    y1 = inptr0[0];
    cb1 = inptr1[0];
    cr1 = inptr2[0];
    y2 = inptr0[1];
    cb2 = inptr1[1];
    cr2 = inptr2[1];
    r = range_limit[y1 + Crrtab[cr1]];
    g = range_limit[y1 + ((int)((Cbgtab[cb1] + Crgtab[cr1]) >> 16))];
    b = range_limit[y1 + Cbbtab[cb1]];
    temp_rgb1 = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));
    r = range_limit[y2 + Crrtab[cr2]];
    g = range_limit[y2 + ((int)((Cbgtab[cb2] + Crgtab[cr2]) >> 16))];
    b = range_limit[y2 + Cbbtab[cb2]];
    temp_rgb2 = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));
    rgb = (temp_rgb2 << 16) | temp_rgb1;
    (*(int *)(outptr)) = rgb;
    inptr0 += 2;
    inptr1 += 2;
    inptr2 += 2;
    outptr += 4;
}
}
