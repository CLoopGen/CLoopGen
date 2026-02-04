#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern  uint8_t *p1;
extern int width;
extern int threshold;
extern  uint8_t *coordinates[];
extern int coord;
extern uint16_t *dst;
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < width; x++) {
    int min = (((const av_alias16 *)(&p1[2 * x]))->u16);
    int limit = ((min - threshold) > (0) ? (min - threshold) : (0));
    for (i = 0; i < 16; i++) {
        int bit_index = i % 8;
        if (coord & (1 << bit_index)) {
            uint16_t candidate = (((const av_alias16 *)(coordinates[bit_index] + x * 2))->u16);
            min = (min > candidate) ? candidate : min;
            min = (min > limit) ? min : limit;
        }
    }
    dst[x] = min;
}
}
