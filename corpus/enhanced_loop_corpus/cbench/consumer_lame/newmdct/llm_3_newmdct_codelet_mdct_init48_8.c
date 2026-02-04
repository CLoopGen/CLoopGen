#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;
extern FLOAT8 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - iterate over rows first, then columns with a fixed stride
    // This changes the access pattern from column-wise (for each i, access win[0..3][i]) to row-strided

    FLOAT8 scale = max / 32768;
    int row_stride = 1;
    int col;

    // Process one row at a time with a stride of 1 across columns
    for (col = 0; col < 36; col++) {
        win[0 * row_stride][col] *= scale;
    }
    for (col = 0; col < 36; col++) {
        win[1 * row_stride][col] *= scale;
    }
    for (col = 0; col < 36; col++) {
        win[3 * row_stride][col] *= scale;
    }
}
