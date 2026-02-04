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
    int local_y, local_cb, local_cr;
    JSAMPROW local_outptr = outptr;
    for (col = 0; col < num_cols; col++) {
        local_y = inptr0[col];
        local_cb = inptr1[col];
        local_cr = inptr2[col];
        local_outptr[0] = range_limit[local_y + Crrtab[local_cr]];
        local_outptr[1] = range_limit[local_y + ((int)((Cbgtab[local_cb] + Crgtab[local_cr]) >> 16))];
        local_outptr[2] = range_limit[local_y + Cbbtab[local_cb]];
        local_outptr += 3;
    }
    outptr = local_outptr;
}
