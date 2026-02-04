#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    JSAMPLE prev_val = 0;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE curr_in = inptr[col];
        outptr[0] = prev_val;          
        outptr[1] = curr_in;            
        outptr[2] = curr_in ^ prev_val; 
        outptr[3] = 255;                
        prev_val = curr_in;             
        outptr += 4;
    }
}
