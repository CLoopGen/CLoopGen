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
    // Reduced effective loop depth by unrolling in blocks of 4, assuming width is multiple of 4
    int i = 0;
    for (; i <= width - 4; i += 4) {
        for (int offset = 0; offset < 4; offset++) {
            x = i + offset;
            int j2 = 2 * (x & 3);
            j = (x & 7);
            if ((dsp_mask << j) & 128) {
                b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
                dst[x >> 2] &= 65343 >> j2;
                dst[x >> 2] |= b << (6 - j2);
            }
            if ((mask << j) & 128)
                src_x++;
        }
    }
    // Handle remaining elements
    for (; i < width; i++) {
        x = i;
        int j2 = 2 * (x & 3);
        j = (x & 7);
        if ((dsp_mask << j) & 128) {
            b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
            dst[x >> 2] &= 65343 >> j2;
            dst[x >> 2] |= b << (6 - j2);
        }
        if ((mask << j) & 128)
            src_x++;
    }
}
