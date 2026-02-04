#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[94];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 - 2; i++) {
    int read_idx_left = i;
    int read_idx_top = i;
    int write_idx_v1 = i * 2;
    int write_idx_v2 = 32 * 2 + i;

    v[write_idx_v1] = (left[read_idx_left + 1] + left[read_idx_left] + 1) >> 1;
    v[write_idx_v1 + 1] = (left[read_idx_left + 2] + (left[read_idx_left + 1] * 2) + left[read_idx_left] + 2) >> 2;
    v[write_idx_v2] = (top[read_idx_top - 1] + (top[read_idx_top] * 2) + top[read_idx_top + 1] + 2) >> 2;
}
}
