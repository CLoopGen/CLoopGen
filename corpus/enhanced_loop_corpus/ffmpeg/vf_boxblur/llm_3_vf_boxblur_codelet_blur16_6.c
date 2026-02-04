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
    // Variant 2: Strided Access with Reverse Accumulation Order
    sum = 0;
    for (x = radius; x >= 0; x--) {  // Reverse iteration
        int src_index_plus = (radius + x) * src_step;
        int src_index_minus = (radius - x) * src_step;
        sum += (src[src_index_plus] - src[src_index_minus]) * inv;
        dst[(radius - x) * dst_step] = sum >> 16;  // Write in reverse order to maintain alignment
    }
}
