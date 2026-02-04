#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest_cb;
extern uint8_t *dest_cr;
extern int uvlinesize;
extern int i;
extern  int block_h;
extern  int bit_depth;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd element in two passes (unrolled-like pattern)
    uint16_t value = 1 << (bit_depth - 1);
    for (i = 0; i < block_h; i++) {
        uint16_t *tmp_cb = (uint16_t *)(dest_cb + i * uvlinesize);
        uint16_t *tmp_cr = (uint16_t *)(dest_cr + i * uvlinesize);
        // First pass: even indices
        for (j = 0; j < 8; j += 2) {
            tmp_cb[j] = tmp_cr[j] = value;
        }
        // Second pass: odd indices (reverse order to alter access pattern further)
        for (j = 7; j >= 0; j -= 2) {
            tmp_cb[j] = tmp_cr[j] = value;
        }
    }
}
