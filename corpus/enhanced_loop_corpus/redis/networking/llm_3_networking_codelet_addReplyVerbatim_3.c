#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ext;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index mapping (using a fixed offset table)
    // Simulates indirect access pattern using a lookup table for indices
    int indices[3] = {0, 1, 2}; // Indirect indexing, though sequential here for correctness
    for (int i = 0; i < 3; i++) {
        int idx = indices[i]; // Base index from "indirect" source
        if (ext[idx] == '\x00') {
            p[idx] = ' ';
        } else {
            p[idx] = ext[idx];
        }
    }
}
