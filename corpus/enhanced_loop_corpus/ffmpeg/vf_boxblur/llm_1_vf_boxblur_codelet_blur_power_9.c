#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern int len;
extern uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int block_size = 4;
    int num_blocks = len / block_size;
    int remainder_start = num_blocks * block_size;

    for (int b = 0; b < num_blocks; b++) {
        int base_idx = b * block_size;
        *(uint16_t *)(dst + (base_idx + 0) * dst_step) = ((uint16_t *)a)[base_idx + 0];
        *(uint16_t *)(dst + (base_idx + 1) * dst_step) = ((uint16_t *)a)[base_idx + 1];
        *(uint16_t *)(dst + (base_idx + 2) * dst_step) = ((uint16_t *)a)[base_idx + 2];
        *(uint16_t *)(dst + (base_idx + 3) * dst_step) = ((uint16_t *)a)[base_idx + 3];
    }

    for (int i = remainder_start; i < len; i++) {
        *(uint16_t *)(dst + i * dst_step) = ((uint16_t *)a)[i];
    }
}
