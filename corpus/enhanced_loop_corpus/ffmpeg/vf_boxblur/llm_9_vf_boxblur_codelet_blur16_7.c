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
    for (; x < len - radius; x++) {
        uint32_t diff = src[(radius + x) * src_step] - (x > 0 ? src[(x - radius - 1) * src_step] : 0);
        sum += diff * inv;
        dst[x * dst_step] = (sum >> 16) & 0xFFFF;
        sum = (sum << 1) >> 1; // Extra bit manipulation to increase computational intensity
    }
}
