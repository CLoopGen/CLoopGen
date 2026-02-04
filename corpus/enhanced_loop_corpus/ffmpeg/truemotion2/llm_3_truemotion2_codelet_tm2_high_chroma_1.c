#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *data;
extern int stride;
extern int *last;
extern unsigned int *CD;
extern int *deltas;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index remapping via an index array
    // Introduce an indirection through an index map to simulate irregular access patterns
    static const int index_map[4] = {0, 2, 1, 3}; // Remap sequential index to original i,j layout
    int *data_ptr = data;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            int flat_idx = index_map[j * 2 + i]; // Use indirect indexing
            CD[j] += deltas[flat_idx];
            last[i] += CD[j];
            data_ptr[i] = last[i];
        }
        data_ptr += stride;
    }
}
