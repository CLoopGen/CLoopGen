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
extern int maxc;
extern uint16_t *dst;
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < width; x += 2) {
    int max1 = (((const av_alias16 *)(&p1[x * 2]))->u16);
    int max2 = (x + 1 < width) ? (((const av_alias16 *)(&p1[(x + 1) * 2]))->u16) : max1;
    int limit1 = ((max1 + threshold) > (maxc) ? (maxc) : (max1 + threshold));
    int limit2 = ((max2 + threshold) > (maxc) ? (maxc) : (max2 + threshold));
    for (i = 0; i < 8; i++) {
        if (coord & (1 << i)) {
            uint8_t* coord_ptr1 = coordinates[i] + x * 2;
            uint8_t* coord_ptr2 = coordinates[i] + (x + 1) * 2;
            int val1 = ((const av_alias16 *)(coord_ptr1))->u16;
            int val2 = (x + 1 < width) ? ((const av_alias16 *)(coord_ptr2))->u16 : val1;
            max1 = (max1 > val1) ? max1 : val1;
            max2 = (max2 > val2) ? max2 : val2;
        }
        max1 = (max1 > limit1) ? limit1 : max1;
        max2 = (max2 > limit2) ? limit2 : max2;
    }
    dst[x] = max1;
    if (x + 1 < width) dst[x + 1] = max2;
}
}
