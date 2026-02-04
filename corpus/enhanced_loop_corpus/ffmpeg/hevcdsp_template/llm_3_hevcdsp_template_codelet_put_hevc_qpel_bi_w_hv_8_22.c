#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using indirect indexing via index array (simulating non-contiguous access)
    // Assume an index mapping for scrambled access (e.g., every 2nd element then wrap) to stress different cache behavior
    int idx[8];
    for (int i = 0; i < 8; i++) {
        idx[i] = (i * 2) % 8; // Create a strided permutation of indices
    }

    for (y = 0; y < height + 7; y++) {
        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            // Access filter and src indirectly using permuted indices
            for (int i = 0; i < 8; i++) {
                int offset = x + idx[i] - 3; // Map [-3, 4] range through shuffled indices
                sum += filter[idx[i]] * src[offset];
            }
            tmp[x] = sum >> 0;
        }
        src += srcstride;
        tmp += 64;
    }
}
