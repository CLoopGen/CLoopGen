#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern  uint8_t *src;
extern int x;
extern int mask;
extern int dsp_mask;
extern int j;
extern int src_x;
extern int b;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < width; x++) {
    int j2 = 4 * (x & 1);
    j = (x & 7);
    if ((dsp_mask << j) & 128) {
        b = (src[src_x >> 1] >> (4 - 4 * (src_x & 1))) & 15;
        dst[x >> 1] &= 65295 >> j2;
        dst[x >> 1] |= b << (4 - j2);
    }
    if ((mask << j) & 128)
        src_x++;
}

}
