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
    int temp_sum = sum;
    for (; x < len; x++) {
        int index1 = (2 * len - radius - x - 1) * src_step;
        int index2 = (x - radius - 1) * src_step;
        temp_sum += (src[index1] - src[index2]) * inv;
        dst[x * dst_step] = temp_sum >> 16;
    }
    sum = temp_sum;
}
