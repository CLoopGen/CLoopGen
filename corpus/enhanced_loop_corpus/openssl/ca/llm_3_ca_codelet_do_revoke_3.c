#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating irregular access pattern)
    int indices[6] = {5, 2, 4, 1, 3, 0}; // Custom permutation of indices
    for (i = 0; i < 6; i++) {
        int idx = indices[i];
        irow[idx] = row[idx];
    }
}
