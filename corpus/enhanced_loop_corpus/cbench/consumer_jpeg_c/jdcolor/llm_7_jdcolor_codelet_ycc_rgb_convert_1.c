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
    JDIMENSION col_step;
    for (col = 0; col < num_cols; col += 2) {
        col_step = (col + 1 < num_cols) ? 2 : 1;

        local_y = ((int)(inptr0[col]));
        local_cb = ((int)(inptr1[col]));
        local_cr = ((int)(inptr2[col]));
        outptr[0] = range_limit[local_y + Crrtab[local_cr]];
        outptr[1] = range_limit[local_y + ((int)((Cbgtab[local_cb] + Crgtab[local_cr]) >> 16))];
        outptr[2] = range_limit[local_y + Cbbtab[local_cb]];

        if (col_step == 2) {
            local_y = ((int)(inptr0[col+1]));
            local_cb = ((int)(inptr1[col+1]));
            local_cr = ((int)(inptr2[col+1]));
            outptr[3] = range_limit[local_y + Crrtab[local_cr]];
            outptr[4] = range_limit[local_y + ((int)((Cbgtab[local_cb] + Crgtab[local_cr]) >> 16))];
            outptr[5] = range_limit[local_y + Cbbtab[local_cb]];
        }

        outptr += 3 * col_step;
    }
}
