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
    for (x = 0; x < w; x++)
        d[2 * x] = d[2 * x + 1] = s1[x];
}

}
