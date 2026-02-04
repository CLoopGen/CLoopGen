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
for (col = 0; col < (num_cols >> 1); col++) {
    if (col % 2 == 0) {
        y = *inptr0++;
        cb = *inptr1++;
        cr = *inptr2++;
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
        b = range_limit[y + Cbbtab[cb]];
        rgb = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));
        y = *inptr0++;
        cb = *inptr1++;
        cr = *inptr2++;
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
        b = range_limit[y + Cbbtab[cb]];
        rgb = ((((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3)) << 16) | rgb);
    } else {
        y = *inptr0++;
        cb = *inptr1++;
        cr = *inptr2++;
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
        b = range_limit[y + Cbbtab[cb]];
        rgb = ((((r) << 8) & 63488) | (((g) << 3) & 2016) | ((b) >> 3));
        rgb = (rgb << 16) | rgb;
    }
    (*(int *)(outptr)) = rgb;
    outptr += 4;
}
}
