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
    if (width <= 0) return;
    int sum_arr[8];
    for (x = 0; x < width; x++) {
        int limit = (p1[x] + threshold) > 255 ? 255 : p1[x] + threshold;
        for (i = 0; i < 8; i++) {
            sum_arr[i] = *(coordinates[i] + x);
        }
        int sum = sum_arr[0] + sum_arr[1] + sum_arr[2] + sum_arr[3] +
                  sum_arr[4] + sum_arr[5] + sum_arr[6] + sum_arr[7];
        int avg = sum / 8;
        dst[x] = avg > p1[x] ? avg : p1[x];
        dst[x] = dst[x] > limit ? limit : dst[x];
    }
}
