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
    uint16_t current_val = ((const av_alias16 *)(&p1[2 * x]))->u16;
    int limit = (current_val > threshold) ? (current_val - threshold) : 0;
    for (i = 0; i < 8; i++) {
        sum += ((const av_alias16 *)(coordinates[i] + x * 2))->u16;
    }
    int avg = sum / 8;
    int clamped_avg = (avg > current_val) ? current_val : avg;
    dst[x] = (clamped_avg > limit) ? clamped_avg : limit;
}
}
