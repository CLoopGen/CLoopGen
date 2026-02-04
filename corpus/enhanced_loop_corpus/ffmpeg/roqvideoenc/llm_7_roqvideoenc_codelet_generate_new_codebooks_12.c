#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int max;
extern uint8_t *yuvClusters;
extern int *points;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = 0;
    for (i = 0; i < max * 24; i++) {
        int offset = i - prev_index; // RAW dependency: current iteration depends on prior value of prev_index
        bias = ((offset % 6) < 4) ? 1 : 1;
        points[i] = bias * yuvClusters[i];
        prev_index = i; // Loop-carried dependency: prev_index carries value to next iteration
    }
}
