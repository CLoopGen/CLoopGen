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
    // Variant 2: Strided memory access with reversed row processing and stride-based column writes
    // Process rows in reverse order and write duplicate pixels with a fixed stride (every 2nd position)
    for (row = num_rows - 1; row >= 0; row--) {
        ptr = image_data[row] + input_cols;
        pixval = ptr[-1];
        // Write to every second location starting from ptr, doubling the span
        for (count = numcols; count > 0; count -= 2) {
            if (count > 0) {
                *ptr = pixval;
                ptr++;
            }
            // Skip one position (strided access)
            if (count > 1) {
                ptr++;
            }
        }
    }
}
