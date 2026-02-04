#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern double **pointers_to_data;
extern double ***pointers_to_pointers;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Nested loop decomposition — original flat loop replaced with nested structure to increase memory access pattern complexity
    // Assuming y acts as a block size, decompose index space into blocks and elements
    int block_size = (y > 0) ? y : 1;
    int num_blocks = (x + block_size - 1) / block_size;  // Ceiling division

    for (int outer = 0; outer < num_blocks; outer++) {
        for (int inner = 0; inner < block_size; inner++) {
            i = outer * block_size + inner;
            if (i >= x) break;
            pointers_to_pointers[i] = pointers_to_data + (i * y);
        }
    }
}
