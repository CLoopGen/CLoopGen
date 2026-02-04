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
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    int cr_val = Crrtab[cr];
    int cb_val = Cbbtab[cb];
    JLONG cbg_crg_sum = Cbgtab[cb] + Crgtab[cr];
    r = range_limit[y + cr_val];
    g = range_limit[y + ((int)(cbg_crg_sum >> 16))];
    b = range_limit[y + cb_val];
    rgb = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    cr_val = Crrtab[cr];
    cb_val = Cbbtab[cb];
    cbg_crg_sum = Cbgtab[cb] + Crgtab[cr];
    r = range_limit[y + cr_val];
    g = range_limit[y + ((int)(cbg_crg_sum >> 16))];
    b = range_limit[y + cb_val];
    rgb = ((rgb << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));
    (*(int *)(outptr)) = rgb;
    outptr += 4;
}
}
