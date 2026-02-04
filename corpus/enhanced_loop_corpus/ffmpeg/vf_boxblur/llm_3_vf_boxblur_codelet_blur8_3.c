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
    // Variant 2: Strided access with reversed traversal (backward iteration)
    int start = len - radius - 1;
    int end = x - 1;

    for (int i = start; i > end; i--) {
        int current_idx = (radius + i) * src_step;
        int prev_idx = (i - radius - 1) * src_step;
        sum += (src[current_idx] - src[prev_idx]) * inv;
        dst[i * dst_step] = sum >> 16;
    }
    x = len - radius; // Ensure x is updated to reflect completion
}
