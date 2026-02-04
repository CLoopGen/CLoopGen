#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties2;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Pointer Arithmetic
    // Use pointer arithmetic to traverse libs1 array indirectly, simulating a scattered access pattern
    // Introduce a temporary pointer to walk through the index array
    int *idx_ptr = libs1;
    for (k = 0; k < liberties2; k++) {
        int current_index = *(idx_ptr + k);  // Indirect indexed access using pointer offset
        if (!(board[current_index] == 0 && ml[current_index] != liberty_mark))
            commonlibs++;
    }
}
