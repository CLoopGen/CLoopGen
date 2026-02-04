#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern INT32 *Crgtab;
extern INT32 *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal (stride of 2, backward)
    JDIMENSION stride = 2;
    JDIMENSION start_col = (num_cols % stride == 0) ? num_cols - stride : (num_cols / stride) * stride;

    for (col = start_col; col < num_cols && col >= 0; col -= stride) {
        // Access current and next element in reverse order within the stride
        JDIMENSION idx1 = col;
        JDIMENSION idx2 = (col + 1 < num_cols) ? col + 1 : col;

        y = ((int)(inptr0[idx1]));
        cb = ((int)(inptr1[idx1]));
        cr = ((int)(inptr2[idx1]));
        outptr[4*(idx1-col)] = range_limit[255 - (y + Crrtab[cr])];
        outptr[4*(idx1-col)+1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
        outptr[4*(idx1-col)+2] = range_limit[255 - (y + Cbbtab[cb])];
        outptr[4*(idx1-col)+3] = inptr3[idx1];

        if (idx2 != idx1) {
            y = ((int)(inptr0[idx2]));
            cb = ((int)(inptr1[idx2]));
            cr = ((int)(inptr2[idx2]));
            outptr[4*(idx2-col)] = range_limit[255 - (y + Crrtab[cr])];
            outptr[4*(idx2-col)+1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
            outptr[4*(idx2-col)+2] = range_limit[255 - (y + Cbbtab[cb])];
            outptr[4*(idx2-col)+3] = inptr3[idx2];
        }
    }
    // Finalize output pointer update assuming full block processed
    outptr += 4 * num_cols;
}
