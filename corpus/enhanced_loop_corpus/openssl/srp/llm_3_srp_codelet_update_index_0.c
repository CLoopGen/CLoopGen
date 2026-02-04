#include <stdio.h>

#include <inttypes.h>

extern char **row;
extern char **irow;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated static mapping)
    int indices[6] = {5, 4, 3, 2, 1, 0}; // Reverse order access
    for (i = 0; i < 6; i++) {
        int mapped_idx = indices[i];
        irow[mapped_idx] = row[mapped_idx];
    }
}
