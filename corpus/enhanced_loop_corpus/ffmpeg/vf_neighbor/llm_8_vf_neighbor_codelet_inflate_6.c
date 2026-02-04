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
    int limit = (p1[x] + threshold) > 255 ? 255 : p1[x] + threshold;
    for (i = 0; i < 4; i++) {
        sum += *(coordinates[i] + x);
    }
    int avg = sum / 4;
    dst[x] = avg > p1[x] ? (avg > limit ? limit : avg) : (p1[x] > limit ? limit : p1[x]);
}
}
