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
    JDIMENSION col_step;
    for (col = 0; col < (num_cols >> 1); col += 2) {
        // Strided memory access: process two iterations with stride of 2
        if (col + 1 < (num_cols >> 1)) {
            col_step = 1;
        } else {
            col_step = 0;
        }

        y = inptr0[col << 1];
        cb = inptr1[col << 1];
        cr = inptr2[col << 1];
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];
        rgb = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));

        y = inptr0[(col << 1) + 1];
        cb = inptr1[(col << 1) + 1];
        cr = inptr2[(col << 1) + 1];
        r = range_limit[y + Crrtab[cr]];
        g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
        b = range_limit[y + Cbbtab[cb]];
        rgb = ((rgb << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));

        if (col_step) {
            y = inptr0[(col << 1) + 2];
            cb = inptr1[(col << 1) + 2];
            cr = inptr2[(col << 1) + 2];
            r = range_limit[y + Crrtab[cr]];
            g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
            b = range_limit[y + Cbbtab[cb]];
            JLONG rgb_next = (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936));

            y = inptr0[(col << 1) + 3];
            cb = inptr1[(col << 1) + 3];
            cr = inptr2[(col << 1) + 3];
            r = range_limit[y + Crrtab[cr]];
            g = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> 16))];
            b = range_limit[y + Cbbtab[cb]];
            rgb_next = ((rgb_next << 16) | (((r) & 248) | ((g) >> 5) | (((g) << 11) & 57344) | (((b) << 5) & 7936)));

            *(int*)(outptr) = rgb;
            *(int*)(outptr + 4) = rgb_next;
            outptr += 8;
        } else {
            *(int*)(outptr) = rgb;
            outptr += 4;
        }
    }
}
