#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bitmap;
extern uint16_t *lut;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with increased stride to traverse sparse regions
    uint8_t *bm = bitmap;
    uint16_t *table = lut;
    int index = k;
    int stride = 4; // Access every 4th byte in bitmap, then check all 8 bits within
    for (i = 0; i < (1 << 16); i += stride * 8) {
        for (int step = 0; step < 8 && (i + (step * stride)) < (1 << 16); ++step) {
            int base_idx = i + (step * stride);
            uint8_t byte = bm[base_idx >> 3];
            for (int bit = 0; bit < 8; ++bit) {
                int idx = base_idx + bit;
                if (idx >= (1 << 16)) break;
                if ((idx == 0) || (byte & (1 << bit)))
                    table[index++] = idx;
            }
        }
    }
    k = index;
}
