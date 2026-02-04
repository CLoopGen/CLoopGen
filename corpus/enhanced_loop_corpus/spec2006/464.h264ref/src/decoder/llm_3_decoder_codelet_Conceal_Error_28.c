#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access Pattern via Linear Indexing
    // Flatten the 2D iteration into a single loop to ensure consecutive memory writes.
    // Assumes that the underlying data may benefit from linear traversal (cache-friendly).
    int idx;
    for (idx = 0; idx < 256; idx++) {
        int row = idx / 16;  // Compute row offset
        int col = idx % 16;  // Compute column offset
        inY[pos_y + row][pos_x + col] = 127;
    }
}
