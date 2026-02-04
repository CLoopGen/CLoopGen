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
JLONG prev_Cbgtab = 0, prev_Crgtab = 0;
int prev_cr = 0, prev_cb = 0;
for (col = 0; col < (num_cols >> 1); col++) {
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    int cr_val = Crrtab[cr];
    int cb_val = Cbbtab[cb];
    JLONG cbg_crg_sum = (col == 0) ? (Cbgtab[cb] + Crgtab[cr]) : (prev_Cbgtab + prev_Crgtab);
    r = range_limit[y + cr_val];
    g = range_limit[y + ((int)(cbg_crg_sum >> 16))];
    b = range_limit[y + cb_val];
    unsigned int pixel1 = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    y = *inptr0++;
    cb = *inptr1++;
    cr = *inptr2++;
    cr_val = Crrtab[cr];
    cb_val = Cbbtab[cb];
    cbg_crg_sum = Cbgtab[cb] + Crgtab[cr];
    r = range_limit[y + cr_val];
    g = range_limit[y + ((int)(cbg_crg_sum >> 16))];
    b = range_limit[y + cb_val];
    unsigned int pixel2 = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));
    rgb = ((pixel1 << 16) | pixel2);
    (*(int *)(outptr)) = rgb;
    outptr += 4;
    prev_Cbgtab = Cbgtab[prev_cb];
    prev_Crgtab = Crgtab[prev_cr];
    prev_cb = cb;
    prev_cr = cr;
}
}
