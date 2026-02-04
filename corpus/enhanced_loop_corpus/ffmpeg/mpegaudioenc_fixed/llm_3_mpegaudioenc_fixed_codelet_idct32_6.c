#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with offset indexing
    // Instead of strided backward access, traverse forward with consecutive indices but simulate equivalent updates
    // Map original indices (31, 29, 27, ..., 3) to a forward loop using index remapping
    int indices[] = {31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3};
    int len = sizeof(indices) / sizeof(indices[0]);
    for (j = 0; j < len; j++) {
        int idx = indices[j];
        tab[idx] += tab[idx - 2];
    }
}
