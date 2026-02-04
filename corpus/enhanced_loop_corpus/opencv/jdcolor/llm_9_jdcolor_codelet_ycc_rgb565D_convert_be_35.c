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
    y = *inptr0;
    cb = *inptr1;
    cr = *inptr2;
    
    int y_plus_cr = y + Crrtab[cr];
    int y_plus_cb = y + Cbbtab[cb];
    int chroma_sum = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);
    
    r = range_limit[y_plus_cr + (d0 & 255)];
    g = range_limit[y + chroma_sum + ((d0 & 255) >> 1)];
    b = range_limit[y_plus_cb + (d0 & 255)];
    
    d0 = (((d0 & 255) << 24) | ((d0 >> 8) & 16777215));
    
    rgb = ((r & 248) | (g >> 5) | ((g & 0x1F) << 11) | ((b & 0x1F) << 5));
    
    (*(int *)(outptr)) = rgb;
    
    inptr0++;
    inptr1++;
    inptr2++;
    outptr += 4;
}
}
