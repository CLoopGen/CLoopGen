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
    // Variant 2: Strided memory access by writing every second element, then filling gaps in a second pass
    for (int row = 0; row < num_rows; row++) {
        ptr = image_data[row] + input_cols;
        pixval = ptr[-1];
        // First pass: write to every 2nd position starting from offset 0
        int stride_count = (numcols + 1) / 2;
        for (int i = 0; i < stride_count; i++) {
            ptr[2 * i] = pixval;
        }
        // Second pass: fill the odd positions if needed
        for (int i = 0; i < stride_count && (2 * i + 1) < numcols; i++) {
            ptr[2 * i + 1] = pixval;
        }
    }
}
