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
for (x = 0; x < width; x += 2) {
    int min1 = (((const av_alias16 *)(&p1[2 * x]))->u16);
    int min2 = (x + 1 < width) ? (((const av_alias16 *)(&p1[2 * (x + 1)]))->u16) : min1;
    int limit1 = ((min1 - threshold) > (0) ? (min1 - threshold) : (0));
    int limit2 = ((min2 - threshold) > (0) ? (min2 - threshold) : (0));
    for (i = 0; i < 4; i++) {
        if (coord & (1 << (2 * i))) {
            min1 = ((min1) > ((((const av_alias16 *)(coordinates[2*i] + x * 2))->u16)) ? ((((const av_alias16 *)(coordinates[2*i] + x * 2))->u16)) : (min1));
        }
        if ((coord & (1 << (2 * i + 1))) && (x + 1 < width)) {
            min2 = ((min2) > ((((const av_alias16 *)(coordinates[2*i+1] + (x + 1) * 2))->u16)) ? ((((const av_alias16 *)(coordinates[2*i+1] + (x + 1) * 2))->u16)) : (min2));
        }
        min1 = ((min1) > (limit1) ? (min1) : (limit1));
        min2 = ((min2) > (limit2) ? (min2) : (limit2));
    }
    dst[x] = min1;
    if (x + 1 < width) {
        dst[x + 1] = min2;
    }
}
}
