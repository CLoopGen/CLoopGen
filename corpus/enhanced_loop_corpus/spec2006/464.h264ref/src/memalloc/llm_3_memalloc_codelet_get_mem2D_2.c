#include <stdio.h>

#include <inttypes.h>

typedef unsigned char byte;

extern byte ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index remapping to access rows indirectly, simulating non-contiguous or reordered access
    // Here, we reverse the order of updates (process rows from top to bottom becomes bottom to top)
    int *indices = (int*)__builtin_alloca(rows * sizeof(int));
    for (int j = 0; j < rows; j++) {
        indices[j] = rows - 1 - j;  // reversed index mapping
    }
    for (int j = 0; j < rows - 1; j++) {
        int current = indices[j];
        int prev = indices[j + 1];
        if (current > 0) {
            (*array2D)[current] = (*array2D)[current - 1] + columns;
        }
    }
}
