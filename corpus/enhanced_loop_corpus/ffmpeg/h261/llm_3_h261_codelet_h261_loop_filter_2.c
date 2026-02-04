#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int y;
extern int xy;
extern int yz;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed inner loop and precomputed indices
    int base_temp, base_src;
    for (y = 0; y < 8; y++) {
        base_temp = y * 8;
        base_src = y * stride;

        // First and last elements handled separately
        src[base_src] = (temp[base_temp] + 2) >> 2;
        src[base_src + 7] = (temp[base_temp + 7] + 2) >> 2;

        // Inner loop accesses temp with unit stride but computes src with fixed stride
        // Processing middle elements in reverse to modify access pattern
        for (x = 6; x >= 1; x--) {
            int temp_idx = base_temp + x;
            src[base_src + x] = (temp[temp_idx - 1] + 2 * temp[temp_idx] + temp[temp_idx + 1] + 8) >> 4;
        }
    }
}
