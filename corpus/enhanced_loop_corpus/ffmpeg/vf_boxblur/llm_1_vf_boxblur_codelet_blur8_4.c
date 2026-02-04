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
    if (x < len) {
        for (int i = x; i < len; i++) {
            sum += (src[(2 * len - radius - i - 1) * src_step] - src[(i - radius - 1) * src_step]) * inv;
            dst[i * dst_step] = sum >> 16;
        }
    }
}
