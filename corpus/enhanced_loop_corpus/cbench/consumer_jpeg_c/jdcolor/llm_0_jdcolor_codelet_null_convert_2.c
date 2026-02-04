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
    ci = 0;
    inptr = input_buf[0][input_row];
    outptr = output_buf[0];
    for (count = num_cols; count > 0; count--) {
        for (ci = 0; ci < num_components; ci++) {
            *outptr = inptr[ci];
            outptr += 1;
        }
        inptr += num_components;
        outptr -= (num_components - 1);
    }
}
