#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *p1;
extern int width;
extern int threshold;
extern  uint8_t *coordinates[];
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < width; x++) {
    int sum = 0;
    uint8_t px = p1[x];
    int limit = (px + threshold) > 255 ? 255 : (px + threshold);
    for (i = 0; i < 8; i++) {
        sum += *(coordinates[i] + x);
    }
    int avg = sum / 8;
    dst[x] = (avg > px ? avg : px) > limit ? limit : (avg > px ? avg : px);
}
}
