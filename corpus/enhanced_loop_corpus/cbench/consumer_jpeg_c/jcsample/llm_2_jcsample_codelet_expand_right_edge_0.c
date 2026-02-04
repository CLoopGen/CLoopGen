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
    // Variant 1: Consecutive memory access using a flat array indexing approach
    // Instead of accessing image_data[row] and then iterating per row, 
    // we treat the entire image as a linear buffer and write pixel values consecutively.
    JSAMPLE *base_ptr;
    int total_pixels = num_rows * input_cols;
    
    for (row = 0; row < num_rows; row++) {
        base_ptr = image_data[row];
        pixval = base_ptr[input_cols - 1]; // Last pixel in the row
        JSAMPLE *end_ptr = base_ptr + input_cols + numcols;
        for (JSAMPLE *p = base_ptr + input_cols; p < end_ptr; p++) {
            *p = pixval;
        }
    }
}
