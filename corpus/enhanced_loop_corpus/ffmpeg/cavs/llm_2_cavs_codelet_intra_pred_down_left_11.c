#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing indices and using local arrays to improve spatial locality
    uint8_t temp_top[12];
    uint8_t temp_left[12];
    int base_idx = x + y + 2 - 1;
    for (int i = 0; i < 12; i++) {
        temp_top[i] = top[base_idx + i];
        temp_left[i] = left[base_idx + i];
    }
    int idx_d = 0;
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            int center = x + y + 2;
            int t_val = ((temp_top[center - 1] + 2 * temp_top[center] + temp_top[center + 1] + 2) >> 2);
            int l_val = ((temp_left[center - 1] + 2 * temp_left[center] + temp_left[center + 1] + 2) >> 2);
            d[idx_d++] = (t_val + l_val) >> 1;
        }
    }
}
