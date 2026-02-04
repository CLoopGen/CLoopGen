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
for (x = 0; x < width; x += 2) {
    int sum1 = 0, sum2 = 0;
    int limit1 = (p1[x] + threshold) > 255 ? 255 : p1[x] + threshold;
    int limit2 = (x + 1 < width) ? ((p1[x+1] + threshold) > 255 ? 255 : p1[x+1] + threshold) : limit1;

    for (i = 0; i < 8; i++) {
        sum1 += *(coordinates[i] + x);
        if (x + 1 < width) {
            sum2 += *(coordinates[i] + x + 1);
        }
    }

    int avg1 = sum1 / 8;
    int val1 = (avg1 > p1[x] ? avg1 : p1[x]);
    dst[x] = val1 > limit1 ? limit1 : val1;

    if (x + 1 < width) {
        int avg2 = sum2 / 8;
        int val2 = (avg2 > p1[x+1] ? avg2 : p1[x+1]);
        dst[x+1] = val2 > limit2 ? limit2 : val2;
    }
}
}
