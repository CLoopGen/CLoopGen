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
    // Variant 2: Strided memory access — write every 2nd element, then fill gaps in a second pass (simulated stride pattern)
    for (row = 0; row < num_rows; row++) {
        ptr = image_data[row] + input_cols;
        pixval = ptr[-1];
        // Write to every second position first (strided access with step 2)
        for (count = numcols / 2; count > 0; count--) {
            ptr[0] = pixval;
            ptr += 2;
        }
        ptr = image_data[row] + input_cols + 1; // Reset offset for odd indices
        // Fill the remaining positions (interleaved pattern)
        for (count = (numcols + 1) / 2; count > 0; count--) {
            ptr[0] = pixval;
            ptr += 2;
        }
    }
}
