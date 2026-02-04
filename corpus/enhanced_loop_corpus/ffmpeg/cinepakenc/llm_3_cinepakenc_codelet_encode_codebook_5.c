#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *codebook;
extern int size;
extern unsigned char *buf;
extern int x;
extern int y;
extern int ret;
extern int entry_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Simulate indirect access by precomputing effective indices into an index array.
    // This models scenarios with irregular access patterns, such as gather operations.
    int *indices = (int*)malloc(size * entry_size * sizeof(int));
    if (!indices) return; // Handle allocation failure
    int idx = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < entry_size; j++)
            indices[idx++] = j + i * entry_size;
    // Now use the precomputed indices for indirect access
    for (idx = 0; idx < size * entry_size; idx++) {
        int j = idx % entry_size;
        buf[ret++] = codebook[indices[idx]] ^ (j >= 4 ? 128 : 0);
    }
    free(indices);
}
