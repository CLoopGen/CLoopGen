#include <stdio.h>

#include <inttypes.h>

extern unsigned char *block;
extern unsigned int blocksize;
extern unsigned int carry;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array (simulated via computed indices)
    // Instead of direct [b], use a precomputed access pattern: reverse sorted odd indices, then even
    // Simulate indirect access by constructing virtual index list on-the-fly

    int *indices = (int*)__builtin_alloca(blocksize * sizeof(int));
    int idx_count = 0;

    // Build indirect access pattern: all odd indices in reverse, then even in reverse
    for (int i = blocksize - 1; i >= 0; i--) if (i % 2 == 1) indices[idx_count++] = i;
    for (int i = blocksize - 1; i >= 0; i--) if (i % 2 == 0) indices[idx_count++] = i;

    // Traverse through the indirect index list
    for (b = 0; b < idx_count && carry != 0; b++) {
        int pos = indices[b];
        carry += block[pos];
        block[pos] = carry & 255;
        carry >>= 8;
    }
}
