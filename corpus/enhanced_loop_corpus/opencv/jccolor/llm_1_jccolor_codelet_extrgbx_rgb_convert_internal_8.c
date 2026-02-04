#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION chunk_size = 4;
    JDIMENSION num_chunks = (num_cols + chunk_size - 1) / chunk_size;
    for (JDIMENSION ch = 0; ch < num_chunks; ch++) {
        JDIMENSION base_col = ch * chunk_size;
        for (JDIMENSION col = 0; col < chunk_size; col++) {
            JDIMENSION global_col = base_col + col;
            if (global_col >= num_cols) break;
            outptr0[global_col] = inptr[0];
            outptr1[global_col] = inptr[1];
            outptr2[global_col] = inptr[2];
            inptr += 4;
        }
    }
}
