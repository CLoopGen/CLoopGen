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
    // Consecutive array access using pointer arithmetic with pre-incremented base pointers
    JSAMPROW local_inptr0 = inptr0;
    JSAMPROW local_inptr1 = inptr1;
    JSAMPROW local_inptr2 = inptr2;
    JSAMPROW local_outptr = outptr;

    for (col = 0; col < (num_cols >> 1); col++) {
        // Access input arrays consecutively via local pointers to improve locality
        y = *local_inptr0++;
        cb = *local_inptr1++;
        cr = *local_inptr2++;

        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];

        rgb = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));

        y = *local_inptr0++;
        cb = *local_inptr1++;
        cr = *local_inptr2++;

        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];

        rgb = ((rgb << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));

        *(int*)local_outptr = rgb;
        local_outptr += 4;
    }

    // Update the original pointers after loop completion
    inptr0 = local_inptr0;
    inptr1 = local_inptr1;
    inptr2 = local_inptr2;
    outptr = local_outptr;
}
