#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***array2D;
extern int rows;
extern int columns;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Index Remapping
    // Use an auxiliary index array to indirectly determine the access order,
    // breaking the natural sequential pattern and introducing data-dependent access.
    // Simulate indirect addressing by reversing the traversal order.
    int *indices = (int*)__builtin_alloca(rows * sizeof(int));
    for (int j = 0; j < rows; j++) {
        indices[j] = rows - 1 - j; // Reverse mapping: last element first
    }
    for (int j = 1; j < rows; j++) {
        int curr = indices[j];
        int prev = indices[j - 1];
        if (curr > 0) {
            (*array2D)[curr] = (*array2D)[prev] + columns;
        }
    }
}
