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
    // Variant 2: Strided memory access — process every 4th column (downsampling in loop)
    const JDIMENSION stride = 4;
    JDIMENSION col;
    JSAMPROW out_row = outptr;
    for (col = 0; col < num_cols; col += stride) {
        y = ((int)(inptr0[col]));
        cb = ((int)(inptr1[col]));
        cr = ((int)(inptr2[col]));

        // Store output with normal sequential write (upsample visually via replication)
        out_row[0] = range_limit[y + Crrtab[cr]];
        out_row[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        out_row[2] = range_limit[y + Cbbtab[cb]];

        out_row += 3; // Sequential output storage
    }
    // Update the external outptr to reflect how much was written
    outptr = out_row;
}
