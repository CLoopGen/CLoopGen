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
extern uint16_t *dst;
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < width; x++) {
    int sum = 0;
    int limit = (((((const av_alias16 *)(&p1[2 * x]))->u16) - threshold) > (0) ? ((((const av_alias16 *)(&p1[2 * x]))->u16) - threshold) : (0));
    for (i = 0; i < 8; sum += (((const av_alias16 *)(coordinates[i++] + x * 2))->u16))
        ;
    dst[x] = ((((sum / 8) > ((((const av_alias16 *)(&p1[2 * x]))->u16)) ? ((((const av_alias16 *)(&p1[2 * x]))->u16)) : (sum / 8))) > (limit) ? (((sum / 8) > ((((const av_alias16 *)(&p1[2 * x]))->u16)) ? ((((const av_alias16 *)(&p1[2 * x]))->u16)) : (sum / 8))) : (limit));
}

}
