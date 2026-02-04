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
    int y;
    for (x = 0; x < len - radius; x++) {
        sum = 0;
        for (y = -radius; y <= radius; y++) {
            if (x + y >= 0 && x + y < len) {
                sum += src[(x + y) * src_step] * inv;
            }
        }
        dst[x * dst_step] = sum >> 16;
    }
}
