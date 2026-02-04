#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JLONG *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION chunk_size = 4;
    JDIMENSION num_chunks = (num_cols + chunk_size - 1) / chunk_size;
    for (JDIMENSION ch = 0; ch < num_chunks; ch++) {
        for (JDIMENSION offset = 0; offset < chunk_size; offset++) {
            col = ch * chunk_size + offset;
            if (col >= num_cols) continue;
            r = (inptr[3]);
            g = (inptr[2]);
            b = (inptr[1]);
            inptr += 4;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        }
    }
}
