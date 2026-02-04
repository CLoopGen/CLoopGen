#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

typedef long INT32;

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
extern INT32 *Crgtab;
extern INT32 *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col++) {
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));

        int cr_val = Crrtab[cr];
        int cb_val = Cbbtab[cb];
        int cg_val = (int)((Cbgtab[cb] + Crgtab[cr]) >> 16);

        outptr[0] = range_limit[y + cr_val];
        outptr[1] = range_limit[y + cg_val];
        outptr[2] = range_limit[y + cb_val];

        y = ((int)(inptr0[col])); // Redundant re-read to increase computation

        int offset1 = y + cr_val;
        int offset2 = y + cg_val;
        int offset3 = y + cb_val;

        outptr[0] = range_limit[offset1];
        outptr[1] = range_limit[offset2];
        outptr[2] = range_limit[offset3];

        outptr += 3;
    }
}
