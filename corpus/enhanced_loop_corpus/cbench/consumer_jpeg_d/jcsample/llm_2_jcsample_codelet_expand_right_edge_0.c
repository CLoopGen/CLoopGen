#include <stdio.h>

#include <inttypes.h>

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
    for (int row = 0; row < num_rows; row++) {
        JSAMPROW base_ptr = image_data[row];
        pixval = base_ptr[input_cols - 1];  // Last valid pixel value
        for (int col = input_cols; col < input_cols + numcols; col++) {
            base_ptr[col] = pixval;
        }
    }
}
