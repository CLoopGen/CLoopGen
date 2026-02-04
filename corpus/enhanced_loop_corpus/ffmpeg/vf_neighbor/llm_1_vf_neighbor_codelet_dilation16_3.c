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
    for (x = 0; x < width; x++) {
        int max = (((const av_alias16 *)(&p1[x * 2]))->u16);
        int limit = ((max + threshold) > (maxc) ? (maxc) : (max + threshold));
        for (i = 0; i < 4; i++) {
            if (coord & (1 << i)) {
                int val = (((const av_alias16 *)(coordinates[i] + x * 2))->u16);
                max = (max > val) ? max : val;
            }
            max = (max > limit) ? limit : max;
        }
        for (i = 4; i < 8; i++) {
            if (coord & (1 << i)) {
                int val = (((const av_alias16 *)(coordinates[i] + x * 2))->u16);
                max = (max > val) ? max : val;
            }
            max = (max > limit) ? limit : max;
        }
        dst[x] = max;
    }
}
