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
extern JSAMPROW inptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;
extern JSAMPLE *range_limit;
extern int *Crrtab;
extern int *Cbbtab;
extern JLONG *Crgtab;
extern JLONG *Cbgtab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION chunk_size = 4;
    JDIMENSION num_chunks = (num_cols + chunk_size - 1) / chunk_size;
    JDIMENSION c, col_local;

    for (c = 0; c < num_chunks; c++) {
        for (col_local = 0; col_local < chunk_size; col_local++) {
            col = c * chunk_size + col_local;
            if (col >= num_cols) break;
            y = inptr0[col];
            cb = inptr1[col];
            cr = inptr2[col];
            outptr[0] = range_limit[255 - (y + Crrtab[cr])];
            outptr[1] = range_limit[255 - (y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16))))];
            outptr[2] = range_limit[255 - (y + Cbbtab[cb])];
            outptr[3] = inptr3[col];
            outptr += 4;
        }
    }
}
