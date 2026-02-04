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
    // Variant 2: Strided memory access - process every second column, then fill backward
    for (row = 0; row < num_rows; row++) {
        ptr = image_data[row] + input_cols - 2;  // Start earlier for strided access
        pixval = ptr[1];  // Original last pixel

        // Write with stride of 2 (every other element)
        for (count = numcols / 2; count > 0; count--) {
            *ptr = pixval;
            *(ptr + 1) = pixval;
            ptr += 2;
        }

        // Handle odd leftover if numcols is odd
        if (numcols % 2) {
            *ptr = pixval;
        }
    }
}
