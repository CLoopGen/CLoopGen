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
    // Variant 1: Consecutive memory access by pre-computing base pointers and using offset indexing
    uint16_t *src_base = src + (radius * src_step);
    uint16_t *dst_base = dst;
    int i = x;
    for (; i < len - radius; i++) {
        sum += (src_base[i * src_step] - src[(i - radius - 1) * src_step]) * inv;
        dst_base[i * dst_step] = sum >> 16;
    }
    x = i;
}
