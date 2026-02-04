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
for (i = 0; i < max * 24; i++) {
    if ((i % 6) >= 4) {
        bias = 1;
    } else {
        bias = 1;
    }
    points[i] = bias * yuvClusters[i];
}
}
