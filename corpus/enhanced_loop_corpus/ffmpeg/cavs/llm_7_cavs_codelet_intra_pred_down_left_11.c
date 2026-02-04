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
    for (y = 0; y < 8; y++) {
        int base_offset = y * stride;
        int left_base = y + 2;
        for (x = 0; x < 8; x++) {
            int diag_idx = x + y;
            int t_idx = diag_idx + 2;
            uint8_t top_val = (top[t_idx - 1] + 2 * top[t_idx] + top[t_idx + 1] + 2) >> 2;
            uint8_t left_val = (left[t_idx - 1] + 2 * left[t_idx] + left[t_idx + 1] + 2) >> 2;
            d[base_offset + x] = (top_val + left_val) >> 1;
        }
    }
}
