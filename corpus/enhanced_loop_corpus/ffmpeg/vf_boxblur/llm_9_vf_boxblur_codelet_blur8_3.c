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
    int step = 2;
    for (; x < len - radius; x += step) {
        int temp1 = src[(radius + x) * src_step];
        int temp2 = src[(x - radius - 1) * src_step];
        sum += (temp1 - temp2) * inv;
        dst[x * dst_step] = sum >> 16;
        if (x + 1 < len - radius) {
            sum += (src[(radius + x + 1) * src_step] - src[(x - radius) * src_step]) * inv;
            dst[(x + 1) * dst_step] = sum >> 16;
        }
    }
}
