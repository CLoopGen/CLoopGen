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



void loop() {
    // Variant 2: Strided memory access with reverse traversal
    // Traverse the array in reverse order with a negative stride
    // This changes spatial locality and may affect cache behavior
    for (x = width - 1; x >= 0; x--) {
        int j2 = 4 * (x & 1);
        j = (x & 7);
        int src_index = src_x >> 1;
        int shift_src = 4 - 4 * (src_x & 1);
        if ((dsp_mask << j) & 128) {
            b = (src[src_index] >> shift_src) & 15;
            int dst_idx = x >> 1;
            dst[dst_idx] &= 65295 >> j2;
            dst[dst_idx] |= b << (4 - j2);
        }
        if ((mask << j) & 128)
            src_x++;
    }
}
