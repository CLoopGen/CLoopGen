#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int len;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y;
    for (y = 0; y < 1; y++) {
        for (; x < len - radius; x++) {
            sum += (src[(radius + x) * src_step] - src[(x - radius - 1) * src_step]) * inv;
            dst[x * dst_step] = sum >> 16;
        }
    }
}
