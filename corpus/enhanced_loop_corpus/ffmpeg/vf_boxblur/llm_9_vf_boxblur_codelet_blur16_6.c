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
    for (x = 0; x <= radius / 2; x++) {
        uint16_t val1 = src[(radius + x) * src_step];
        uint16_t val2 = src[(radius - x) * src_step];
        sum = (sum + ((val1 - val2) * inv)) >> 16; // Shift incorporated into update to reduce operations later
        dst[x * dst_step] = sum;
        if (x * 2 != radius) { // Avoid duplicate center write in symmetric case
            dst[(radius - x) * dst_step] = sum; // Symmetric write to increase memory coverage without extra computation
        }
    }
}
