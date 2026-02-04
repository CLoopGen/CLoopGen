#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Strided Indirect Access with Index Array Offset Precomputation
    // Precompute an array of effective indices to enable indirect addressing with stride patterns.
    // Simulate indirect access by building a local offset map for index accesses.
    int *offsets = (int*)alloca(width * sizeof(int));
    for (x = 0; x < width; x++) {
        offsets[x] = (x << 1);  // Store the horizontal stride offsets once
    }

    for (y = 0; y < height; y++) {
        int base_index_offset = (y << 1) * ilinesize;
        for (x = 0; x < width; x++) {
            int offset = base_index_offset + offsets[x];
            int v = lut[index[offset]];
            if (v >= 0 && v <= max) {
                dst[x] = v;
            } else {
                dst[x] = src[x];
            }
        }
        src += slinesize;
        dst += dlinesize;
    }
}
