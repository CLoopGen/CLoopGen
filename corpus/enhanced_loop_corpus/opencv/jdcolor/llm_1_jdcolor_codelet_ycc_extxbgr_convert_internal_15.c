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
JDIMENSION chunk, offset;
for (chunk = 0; chunk < total_chunks; chunk++) {
    for (offset = 0; offset < chunk_size; offset++) {
        col = chunk * chunk_size + offset;
        if (col >= num_cols) break;
        y = inptr0[col];
        cb = inptr1[col];
        cr = inptr2[col];
        outptr[3] = range_limit[y + Crrtab[cr]];
        outptr[2] = range_limit[y + ((int)((Cbgtab[cb] + Crgtab[cr]) >> (16)))];
        outptr[1] = range_limit[y + Cbbtab[cb]];
        outptr[0] = 255;
        outptr += 4;
    }
}
}
