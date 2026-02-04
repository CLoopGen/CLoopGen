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
JSAMPROW temp_out = output_buf[0];
for (ci = 0; ci < num_components; ci++) {
    inptr = input_buf[ci][input_row];
    for (count = 0; count < num_cols; count++) {
        temp_out[ci + count * num_components] = inptr[count];
    }
}
}
