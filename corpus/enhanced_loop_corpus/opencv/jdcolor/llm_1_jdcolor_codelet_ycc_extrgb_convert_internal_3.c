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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION chunk_size = 4;
    JDIMENSION total_chunks = (num_cols + chunk_size - 1) / chunk_size;
    JDIMENSION chunk, col_step;
    for (chunk = 0; chunk < total_chunks; chunk++) {
        col_step = chunk * chunk_size;
        JDIMENSION end_col = col_step + chunk_size <= num_cols ? col_step + chunk_size : num_cols;
        for (col = col_step; col < end_col; col++) {
            y = inptr0[col];
            cb = inptr1[col];
            cr = inptr2[col];
            outptr[0] = range_limit[y + Crrtab[cr]];
            outptr[1] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
            outptr[2] = range_limit[y + Cbbtab[cb]];
            outptr += 3;
        }
    }
}
