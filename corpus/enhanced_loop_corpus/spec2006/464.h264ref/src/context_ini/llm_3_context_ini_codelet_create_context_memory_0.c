#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an index mapping array to access elements in a non-sequential order.
    // Simulate indirect access using a precomputed index permutation (simplified as reverse order).
    int *indices = (int*)__builtin_alloca(number_of_slices * sizeof(int));
    for (int idx = 0; idx < number_of_slices; idx++) {
        indices[idx] = number_of_slices - 1 - idx; // Reverse order access
    }
    for (k = 0; k < 3; k++) {
        for (i = 0; i < 4; i++) {
            for (int idx = 0; idx < number_of_slices; idx++) {
                int j = indices[idx]; // Indirect access through index array
                initialized[k][i][j] = 0;
            }
        }
    }
}
