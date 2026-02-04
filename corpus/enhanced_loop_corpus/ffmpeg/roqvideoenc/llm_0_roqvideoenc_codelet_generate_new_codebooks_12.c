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
    for (int outer = 0; outer < max; outer++) {
        for (int inner = 0; inner < 24; inner++) {
            int i = outer * 24 + inner;
            bias = ((i % 6) < 4) ? 1 : 1;
            points[i] = bias * yuvClusters[i];
        }
    }
}
