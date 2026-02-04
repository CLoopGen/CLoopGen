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
int trip_count = (width + 3) / 4;
for (x = 0; x < trip_count; x++) {
    int base_x = 4 * x;
    for (int offset = 0; offset < 4; offset++) {
        int idx = base_x + offset;
        if (idx >= width) break;
        j = (idx & 7);
        int j2 = 2 * (idx & 3);
        
        if ((dsp_mask << j) & 128) {
            b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
            dst[idx >> 2] &= 65343 >> j2;
            dst[idx >> 2] |= b << (6 - j2);
        }
        if ((mask << j) & 128)
            src_x++;
    }
}
}
