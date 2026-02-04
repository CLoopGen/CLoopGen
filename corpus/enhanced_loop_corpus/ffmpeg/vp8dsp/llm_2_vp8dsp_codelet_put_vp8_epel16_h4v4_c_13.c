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
    // Variant 1: Consecutive memory access by unrolling and reordering computation to access tmp elements in increasing order
    for (y = 0; y < h; y++) {
        uint8_t temp_vals[16];
        // Precompute the weighted sum using reordered memory accesses for better spatial locality
        for (x = 0; x < 16; x++) {
            int index = x * 16; // Base offset for current column across rows in tmp
            int sum = filter[2] * tmp[index + 0] +
                      filter[3] * tmp[index + 16] -
                      filter[1] * tmp[index - 16] -
                      filter[4] * tmp[index + 32] + 64;
            temp_vals[x] = cm[sum >> 7];
        }
        // Store results consecutively into dst
        for (x = 0; x < 16; x++) {
            dst[x] = temp_vals[x];
        }
        dst += dststride;
        tmp += 16;
    }
}
