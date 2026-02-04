#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src2;
extern uint8_t *dst2;
extern int srcStride2;
extern int dstStride2;
extern int x;
extern int y;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        const uint8_t *s2 = src2 + srcStride2 * (y >> 1);
        uint8_t *d = dst2 + dstStride2 * y;
        uint8_t temp_val;
        for (x = 0; x < w; x++) {
            temp_val = s2[x];           // Introduce temporary to modify data flow
            d[2 * x] = temp_val;        // RAW dependency: d[2*x] depends on temp_val
            d[2 * x + 1] = temp_val;    // Reuse same value, removes redundant load from s2
        }
    }
}
