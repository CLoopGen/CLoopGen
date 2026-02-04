#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY image_data;
extern int num_rows;
extern JDIMENSION input_cols;
extern JSAMPROW ptr;
extern JSAMPLE pixval;
extern int count;
extern int row;
extern int numcols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal and direct array indexing
    for (row = 0; row < num_rows; row++) {
        ptr = image_data[row];
        pixval = ptr[input_cols - 1];  // Last valid pixel value in the row
        for (count = input_cols; count < input_cols + numcols; count++) {
            ptr[count] = pixval;
        }
    }
}
