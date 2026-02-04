#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
extern JDIMENSION col;
extern int num_components;
extern JDIMENSION num_cols;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ci = 0;
    col = 0;
    inptr = input_buf[ci][input_row];
    outptr = *output_buf;
    for (; ci < num_components; ) {
        if (col < num_cols) {
            outptr[ci] = inptr[col];
            outptr += num_components;
            col++;
        } else {
            ci++;
            if (ci < num_components) {
                inptr = input_buf[ci][input_row];
                outptr = *output_buf;
                col = 0;
            }
        }
    }
}
