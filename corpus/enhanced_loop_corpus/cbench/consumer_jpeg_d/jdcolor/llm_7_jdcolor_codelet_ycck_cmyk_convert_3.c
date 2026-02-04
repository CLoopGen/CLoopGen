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
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern INT32 *Crgtab;
extern INT32 *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (col = 0; col < num_cols; col++) {
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));

        // Eliminate some loop-carried dependencies by unrolling two iterations
        if (col + 1 < num_cols) {
            // Process current and next element in parallel without interleaving writes
            JSAMPLE y_next = inptr0[col + 1];
            JSAMPLE cb_next = inptr1[col + 1];
            JSAMPLE cr_next = inptr2[col + 1];

            outptr[0] = range_limit[255 - (y + Crrtab[cr])];
            outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
            outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
            outptr[3] = inptr3[col];

            outptr[4] = range_limit[255 - ((int)y_next + Crrtab[(int)cr_next])];
            outptr[5] = range_limit[255 - ((int)y_next + ((int)((Cbgtab[(int)cb_next] + Crgtab[(int)cr_next]) >> 16)))];
            outptr[6] = range_limit[255 - ((int)y_next + Cbbtab[(int)cb_next])];
            outptr[7] = inptr3[col + 1];

            outptr += 8;
            col++; // Skip next iteration
        } else {
            // Handle last odd element
            outptr[0] = range_limit[255 - (y + Crrtab[cr])];
            outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16)))];
            outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
            outptr[3] = inptr3[col];
            outptr += 4;
        }
    }
}
