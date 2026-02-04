#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Local Accumulation
    // Instead of accessing tmp with large strides, we preload a local window to enable sequential access.
    for (y = 0; y < h; y++) {
        int16_t temp_window[20]; // Extended buffer to cover indices from x-32 to x+48 (in steps of 16)
        for (int i = 0; i < 20; i++) {
            temp_window[i] = tmp[i * 16 - 32]; // Preload values in increasing address order
        }
        for (x = 0; x < 16; x++) {
            int sum = filter[2] * temp_window[x + 2]  // x + 0*16 -> index x+2 in window
                    - filter[1] * temp_window[x + 1]  // x - 1*16 -> index x+1
                    + filter[0] * temp_window[x + 0]  // x - 2*16 -> index x+0
                    + filter[3] * temp_window[x + 3]  // x + 1*16 -> index x+3
                    - filter[4] * temp_window[x + 4]  // x + 2*16 -> index x+4
                    + filter[5] * temp_window[x + 5]; // x + 3*16 -> index x+5
            dst[x] = cm[(sum + 64) >> 7];
        }
        dst += dststride;
        tmp += 16;
    }
}
