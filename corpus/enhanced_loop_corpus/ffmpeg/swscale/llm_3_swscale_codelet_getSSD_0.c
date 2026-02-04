#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int w;
extern int h;
extern int x;
extern int y;
extern uint64_t ssd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order (column-major traversal) to change access pattern
    ssd = 0; // Reset accumulator to ensure correctness in repeated calls
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            int d = src1[x + y * stride1] - src2[x + y * stride2];
            ssd += d * d;
        }
    }
}
