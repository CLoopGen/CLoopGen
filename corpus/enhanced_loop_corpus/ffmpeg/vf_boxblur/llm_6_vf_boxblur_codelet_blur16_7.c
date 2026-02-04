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
    int temp_sum = sum;
    for (; x < len - radius; x++) {
        temp_sum += (src[(radius + x) * src_step] - src[(x - radius - 1) * src_step]) * inv;
        dst[x * dst_step] = temp_sum >> 16;
    }
    sum = temp_sum;
}
