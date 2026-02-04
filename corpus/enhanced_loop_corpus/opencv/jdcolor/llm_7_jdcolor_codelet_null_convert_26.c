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
    JDIMENSION total_elements = num_cols * num_components;
    outptr = *output_buf;
    for (col = 0; col < num_cols; col++) {
        for (ci = 0; ci < num_components; ci++) {
            inptr = input_buf[ci][input_row];
            outptr[ci + col * num_components] = inptr[col];
        }
    }
}
