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
JLONG local_d0 = d0;
unsigned int local_rgb = 0;

for (col = 0; col < (num_cols >> 1); col++) {
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    int noise = (local_d0) & 255;
    r = range_limit[(y + Crrtab[cr]) + noise];
    g = range_limit[(y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))) + (noise >> 1)];
    b = range_limit[(y + Cbbtab[cb]) + noise];
    local_d0 = ((noise << 24) | ((local_d0 >> 8) & 16777215));
    local_rgb = (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3));

    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    noise = (local_d0) & 255;
    r = range_limit[(y + Crrtab[cr]) + noise];
    g = range_limit[(y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))) + (noise >> 1)];
    b = range_limit[(y + Cbbtab[cb]) + noise];
    local_d0 = ((noise << 24) | ((local_d0 >> 8) & 16777215));
    local_rgb |= (((r << 8) & 63488) | ((g << 3) & 2016) | (b >> 3)) << 16;

    ((*(int *)(outptr)) = local_rgb);
    outptr += 4;
}

d0 = local_d0;
rgb = local_rgb;
}
