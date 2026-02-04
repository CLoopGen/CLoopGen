#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int dst_step;
extern  uint16_t *src;
extern int src_step;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (x = 0; x <= radius * 2; x += 2) {
        int idx1 = (radius + x/2) * src_step;
        int idx2 = (radius - x/2) * src_step;
        sum += (src[idx1] - src[idx2]) * inv;
        dst[(x/2) * dst_step] = sum >> 16;
        sum += (src[idx1 + src_step] - src[idx1 - src_step]) * inv; // Extra operation to increase computational load
    }
}
