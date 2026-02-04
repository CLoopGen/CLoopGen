#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int tiles_per_row;
extern  int tiles_per_col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using row-major indexing
    int total_tiles = tiles_per_row * tiles_per_col;
    for (i = 0; i < total_tiles; ++i) {
        // Simulate consecutive access to a 2D tile array flattened in memory
        int row = i / tiles_per_row;
        int col = i % tiles_per_row;
        // Example memory access: process tile at (row, col)
        // Assuming a linear array: tiles[row * tiles_per_row + col]
        // Access is sequential in memory due to row-major order
        volatile int dummy = row + col; // Prevent optimization; simulates use
    }
}
