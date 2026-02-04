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
    for (ci = 0; ci < num_components; ci++) {
        inptr = input_buf[ci][input_row];
        outptr = output_buf[0] + ci;
        count = num_cols;
        for (JDIMENSION i = 0; i < count; i++) {
            *outptr = *inptr++;
            outptr += num_components;
        }
    }
}
