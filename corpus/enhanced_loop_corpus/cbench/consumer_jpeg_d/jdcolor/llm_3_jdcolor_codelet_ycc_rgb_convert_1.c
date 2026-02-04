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
    // Variant 2: Strided Memory Access (reverse traversal with stride of 1)
    // The arrays are accessed in reverse order (from end to start), introducing a different memory access pattern.
    // This could be useful in scenarios where data is processed backwards or pipelined from the end.

    JDIMENSION col;
    JSAMPROW local_outptr = outptr + 3 * (num_cols - 1);  // Point to last output location

    for (col = num_cols; col > 0; ) {
        col--;
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));

        local_outptr[0] = range_limit[y + Crrtab[cr]];
        local_outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        local_outptr[2] = range_limit[y + Cbbtab[cb]];

        local_outptr -= 3;  // Move backward in output buffer
    }
    // Note: outptr is not modified globally here; if needed, update externally.
}
