#include <stdio.h>

#include <inttypes.h>

extern int M;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried WAW and WAR dependencies via reversed order and accumulation
    int accumulator = -987654321;
    for (k = M; k >= 0; k--) {  // Reverse iteration introduces loop-carried dependence
        mmx[0][k] = accumulator;            // WAW: multiple writes to mmx[0][k] across iterations if overlapping
        accumulator = imx[0][k] + dmx[0][k] + 1;  // WAR: imx/dmx read after potential future write in original direction
        imx[0][k] = -987654321;
        dmx[0][k] = -987654321;
    }
}
