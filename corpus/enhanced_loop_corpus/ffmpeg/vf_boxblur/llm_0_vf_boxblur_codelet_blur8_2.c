#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth = 0; depth < 2; depth++) {
    for (x = 0; x <= radius; x++) {
        sum += (src[(radius + x) * src_step] - src[(radius - x) * src_step]) * inv;
        dst[x * dst_step] = sum >> 16;
    }
}
}
