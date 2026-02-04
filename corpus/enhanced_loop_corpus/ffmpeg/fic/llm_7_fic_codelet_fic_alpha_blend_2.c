#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern uint8_t *alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    uint8_t *local_alpha = alpha;
    int local_size = size;
    for (i = 0; i < local_size; i++) {
        uint8_t diff = local_src[i] - local_dst[i];
        uint16_t product = diff * local_alpha[i];
        local_dst[i] = (uint8_t)(local_dst[i] + (product >> 8));
    }
}
