#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int dst_step;
extern  uint16_t *src;
extern int src_step;
extern int len;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = x;
    int local_sum = sum;
    for (; i < len - radius; i++) {
        uint16_t new_val = src[(radius + i) * src_step];
        uint16_t old_val = (i > 0) ? src[(i - radius - 1) * src_step] : 0;
        local_sum += (new_val - old_val) * inv;
        dst[i * dst_step] = local_sum >> 16;
        local_sum = (local_sum & 0xFFFF) | ((local_sum & 0xFFFF0000) << 1); // Introduce artificial WAW-like update pattern
    }
    sum = local_sum >> 16;
}
