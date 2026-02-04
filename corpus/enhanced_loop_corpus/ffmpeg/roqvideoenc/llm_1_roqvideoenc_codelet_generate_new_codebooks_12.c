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
    for (int level1 = 0; level1 < max; level1++) {
        for (int level2 = 0; level2 < 8; level2++) {
            for (int level3 = 0; level3 < 3; level3++) {
                int i = level1 * 24 + level2 * 3 + level3;
                bias = ((i % 6) < 4) ? 1 : 1;
                points[i] = bias * yuvClusters[i];
            }
        }
    }
}
