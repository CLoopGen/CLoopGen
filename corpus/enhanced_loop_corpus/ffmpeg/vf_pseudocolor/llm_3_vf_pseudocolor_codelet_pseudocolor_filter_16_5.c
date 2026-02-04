#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern  uint16_t *_usr_index;
extern  uint16_t *src;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Strided memory access with indirect indexing (reverse traversal with stride of 2)
    // Access elements in reverse order with a fixed stride to create non-consecutive access pattern
    for (y = 0; y < height; y++) {
        for (x = width - 1; x >= 0; x -= 2) {
            int v = lut[index[x]];
            dst[x] = (v >= 0 && v <= max) ? v : src[x];

            // Handle adjacent element if within bounds
            if (x > 0) {
                int v_prev = lut[index[x - 1]];
                dst[x - 1] = (v_prev >= 0 && v_prev <= max) ? v_prev : src[x - 1];
            }
        }
        index += ilinesize / 2;
        src += slinesize / 2;
        dst += dlinesize / 2;
    }
}
