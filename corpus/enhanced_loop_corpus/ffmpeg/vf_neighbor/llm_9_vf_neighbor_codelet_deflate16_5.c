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
if (width <= 0) return;
for (x = 0; x < width; x += 2) {
    int sum1 = 0, sum2 = 0;
    uint16_t val1 = ((const av_alias16 *)(&p1[2 * x]))->u16;
    uint16_t val2 = (x + 1 < width) ? ((const av_alias16 *)(&p1[2 * (x + 1)]))->u16 : val1;
    int limit1 = (val1 > threshold) ? val1 - threshold : 0;
    int limit2 = (val2 > threshold) ? val2 - threshold : 0;

    for (i = 0; i < 8; i++) {
        sum1 += ((const av_alias16 *)(coordinates[i] + x * 2))->u16;
        if (x + 1 < width) {
            sum2 += ((const av_alias16 *)(coordinates[i] + (x + 1) * 2))->u16;
        }
    }

    int avg1 = sum1 / 8;
    int avg2 = sum2 / 8;
    dst[x] = (avg1 > val1 ? avg1 : val1) > limit1 ? (avg1 > val1 ? avg1 : val1) : limit1;

    if (x + 1 < width) {
        dst[x + 1] = (avg2 > val2 ? avg2 : val2) > limit2 ? (avg2 > val2 ? avg2 : val2) : limit2;
    }
}
}
