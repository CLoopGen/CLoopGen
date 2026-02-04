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
    int limit = (min > threshold) ? (min - threshold) : 0;
    for (i = 0; i < 8; i++) {
        if ((coord >> i) & 1) {
            int val = (((const av_alias16 *)(coordinates[i] + x * 2))->u16);
            min = (val < min) ? val : min;
        }
        min = (min < limit) ? limit : min;
    }
    dst[x] = min;
}
}
