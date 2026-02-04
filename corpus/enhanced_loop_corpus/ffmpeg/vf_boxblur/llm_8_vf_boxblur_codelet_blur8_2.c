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
    int x_inner;
    for (x = 0; x <= radius; x++) {
        sum += (src[(radius + x) * src_step] - src[(radius - x) * src_step]) * inv;
        dst[x * dst_step] = sum >> 16;
        // Add extra computational work without changing trip count
        for (x_inner = 1; x_inner < 4; x_inner++) {
            sum -= (src[(radius + x - x_inner) * src_step] - src[(radius - x + x_inner) * src_step]) * (inv >> x_inner);
        }
    }
}
