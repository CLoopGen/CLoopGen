#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern uint8_t *dst1;
extern int srcStride1;
extern int dstStride1;
extern int x;
extern int y;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        const uint8_t *s1 = src1 + srcStride1 * (y >> 1);
        uint8_t *d = dst1 + dstStride1 * y;
        uint8_t temp_val;
        for (x = 0; x < w; x++) {
            temp_val = s1[x];           // Introduce temporary to modify data flow
            d[2 * x] = temp_val;         // RAW dependency: d[2*x] depends on temp_val
            d[2 * x + 1] = temp_val;     // No WAW between d[2*x] and d[2*x+1], but both depend on same temp_val
        }
    }
}
