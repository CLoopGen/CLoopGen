#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= radius; x++) {
        int index_pos = (radius + x) * src_step;
        int index_neg = (radius - x) * src_step;
        uint8_t src_pos = src[index_pos];
        uint8_t src_neg = src[index_neg];
        sum += (src_pos - src_neg) * inv;
        if (sum > 0) {
            dst[x * dst_step] = sum >> 16;
        }
    }
}
