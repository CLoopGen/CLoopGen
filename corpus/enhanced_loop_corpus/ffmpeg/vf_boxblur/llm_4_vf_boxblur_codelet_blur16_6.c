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
    int limit = radius + 1;
    for (x = 0; x < limit; x++) {
        uint16_t val_plus = src[(radius + x) * src_step];
        uint16_t val_minus = src[(radius - x) * src_step];
        sum += (val_plus - val_minus) * inv;
        dst[x * dst_step] = sum >> 16;
    }
}
