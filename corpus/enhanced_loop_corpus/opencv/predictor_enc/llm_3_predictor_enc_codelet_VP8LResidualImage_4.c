#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int tiles_per_row;
extern  int tiles_per_col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with vertical traversal (column stride)
    int total_rows = tiles_per_col;
    int total_cols = tiles_per_row;
    int stride = total_rows;
    int n_elements = total_rows * total_cols;
    
    // Traverse in strided manner: fix column, step by column height (stride)
    for (i = 0; i < n_elements; ++i) {
        int col = i / total_rows;           // current column
        int row = i % total_rows;           // current row within column
        int linear_index = col + row * total_cols; // Original (row-major) index
        // Simulate strided access: processing down columns instead of across rows
        // This creates non-consecutive memory accesses when moving to next element in column
        volatile int dummy = linear_index; // Simulated access to data[linear_index]
    }
}
