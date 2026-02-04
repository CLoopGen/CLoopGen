#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint8_t *src;
extern  uint8_t *top;
extern  uint8_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Intermediate Index Array (Indirect Access Simulation)
    // Use a precomputed index array to simulate indirect access pattern, accessing src non-sequentially
    // This variant mimics irregular access useful in some transform kernels.
    ptrdiff_t s = stride;
    int idx[64]; // Assuming maximum size is 64 for stack allocation safety
    if (size > 64) return; // Avoid buffer overflow

    // Precompute scrambled indices: interleave rows with offset
    for (int i = 0; i < size; i++)
        idx[i] = (i * 31) % size; // Prime-stride permutation for pseudo-random access

    for (int iy = 0; iy < size; iy++) {
        int y = idx[iy];
        for (int ix = 0; ix < size; ix++) {
            int x = idx[ix];
            src[(x) + s * (y)] = ((size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
        }
    }
}
