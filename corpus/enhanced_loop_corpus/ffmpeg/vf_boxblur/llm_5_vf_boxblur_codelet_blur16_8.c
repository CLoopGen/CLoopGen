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
    for (; x < len && inv != 0; x++) {
        int read_idx_neg = x - radius - 1;
        int read_idx_pos = 2 * len - radius - x - 1;
        uint16_t src_val_pos = src[read_idx_pos * src_step];
        uint16_t src_val_neg = (read_idx_neg >= 0) ? src[read_idx_neg * src_step] : 0;
        sum += (src_val_pos - src_val_neg) * inv;
        if ((sum >> 16) >= 0) {
            dst[x * dst_step] = sum >> 16;
        } else {
            dst[x * dst_step] = 0;
        }
    }
}
