#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *clut;
extern uint8_t list_inv[256];
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access over list_inv with indirect indexing via auxiliary stride array concept
    int stride = 2; // Simulate strided access
    int limit = (i < 0) ? 0 : i;
    for (int j = 0; j <= limit; j += stride) {
        int actual_i = i - j; // Indirect decreasing index
        if (actual_i < 0) break;
        int v = actual_i * 255 / count;
        int lookup_idx = list_inv[actual_i];
        ((((union unaligned_32 *)(clut + 4 * lookup_idx))->l) = ((((unsigned int)(v) << 24) | ((v / 2) << 16) | ((v) << 8) | (v / 2))));
        // Process next strided element if within bounds
        if (j + 1 <= limit && actual_i - 1 >= 0) {
            actual_i = actual_i - 1;
            v = actual_i * 255 / count;
            lookup_idx = list_inv[actual_i];
            ((((union unaligned_32 *)(clut + 4 * lookup_idx))->l) = ((((unsigned int)(v) << 24) | ((v / 2) << 16) | ((v) << 8) | (v / 2))));
        }
    }
    i = -1; // Ensure original exit condition met
}
