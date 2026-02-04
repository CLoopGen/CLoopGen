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
    for (x = 0; x <= radius; x++) {
        if ((radius - x) >= 0) {
            sum += (src[(radius + x) * src_step] - src[(radius - x) * src_step]) * inv;
            dst[x * dst_step] = sum >> 16;
        } else {
            dst[x * dst_step] = 0;
        }
    }
}
