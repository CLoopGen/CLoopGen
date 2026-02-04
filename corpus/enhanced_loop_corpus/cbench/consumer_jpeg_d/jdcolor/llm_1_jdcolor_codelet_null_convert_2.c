#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef JSAMPARRAY *JSAMPIMAGE;

typedef unsigned int JDIMENSION;

extern JSAMPIMAGE input_buf;
extern JDIMENSION input_row;
extern JSAMPARRAY output_buf;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION count;
extern int num_components;
extern JDIMENSION num_cols;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION total_elements = num_cols * num_components;
    outptr = output_buf[0];
    for (JDIMENSION idx = 0; idx < total_elements; idx++) {
        JDIMENSION col = idx % num_cols;
        JDIMENSION comp = idx / num_cols;
        JSAMPROW inptr_local = input_buf[comp][input_row];
        outptr[idx] = inptr_local[col];
    }
}
