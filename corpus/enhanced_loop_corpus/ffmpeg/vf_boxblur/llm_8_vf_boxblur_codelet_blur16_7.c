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
    int y;
    for (y = 0; y < len - radius; y += 2) {
        sum += (src[(radius + y) * src_step] - src[(y - radius - 1) * src_step]) * inv;
        dst[y * dst_step] = sum >> 16;
        if (y + 1 < len - radius) {
            sum += (src[(radius + y + 1) * src_step] - src[(y - radius) * src_step]) * inv;
            dst[(y + 1) * dst_step] = sum >> 16;
        }
    }
}
