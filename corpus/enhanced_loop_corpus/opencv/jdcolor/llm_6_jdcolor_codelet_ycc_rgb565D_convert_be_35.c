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
for (col = 0; col < (num_cols >> 1); col++) {
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    int temp_d0_low = (d0) & 255;
    r = range_limit[((y + Crrtab[cr]) + temp_d0_low)];
    g = range_limit[((y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))) + (temp_d0_low >> 1))];
    b = range_limit[((y + Cbbtab[cb]) + temp_d0_low)];
    d0 = ((temp_d0_low << 24) | (((d0) >> 8) & 16777215));
    rgb = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    temp_d0_low = (d0) & 255;
    r = range_limit[((y + Crrtab[cr]) + temp_d0_low)];
    g = range_limit[((y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))) + (temp_d0_low >> 1))];
    b = range_limit[((y + Cbbtab[cb]) + temp_d0_low)];
    d0 = ((temp_d0_low << 24) | (((d0) >> 8) & 16777215));
    rgb = ((rgb << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));
    (*(int *)(outptr)) = rgb;
    outptr += 4;
}
}
