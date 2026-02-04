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
for (col = 0; col < num_cols; col++) {
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    r = range_limit[(y + Crrtab[cr]) & 255];
    g = range_limit[(y + ((Cbgtab[cb] + Crgtab[cr]) >> 16)) & 255];
    b = range_limit[(y + Cbbtab[cb]) & 255];
    rgb = ((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3);
    *(int*)outptr = rgb;
    outptr += 2;
}
}
