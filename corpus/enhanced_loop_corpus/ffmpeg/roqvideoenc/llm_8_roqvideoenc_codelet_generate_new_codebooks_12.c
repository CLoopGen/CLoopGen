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
for (i = 0; i < max * 12; i++) {
    int idx1 = i;
    int idx2 = i + max * 12;
    bias = ((i % 3) < 2) ? 1 : 1;
    points[idx1] = bias * yuvClusters[idx1];
    points[idx2] = bias * yuvClusters[idx2];
}
}
