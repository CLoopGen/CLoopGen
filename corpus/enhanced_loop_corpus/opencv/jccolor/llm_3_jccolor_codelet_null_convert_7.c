#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef JSAMPARRAY *JSAMPIMAGE;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY input_buf;
extern JSAMPIMAGE output_buf;
extern JDIMENSION output_row;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION count;
extern int num_comps;
extern JDIMENSION num_cols;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ci = 0; ci < num_comps; ci++) {
    JSAMPROW temp_in = input_buf[0] + ci;
    JSAMPROW temp_out = output_buf[ci][output_row];
    JDIMENSION idx;
    for (idx = 0; idx < num_cols; idx++) {
        temp_out[idx] = temp_in[idx << 2]; // Strided access with fixed stride of 4 (example optimization when num_comps is power of two)
    }
}
}
