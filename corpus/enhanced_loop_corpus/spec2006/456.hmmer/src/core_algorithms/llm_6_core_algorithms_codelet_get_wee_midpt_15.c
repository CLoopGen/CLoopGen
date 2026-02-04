#include <stdio.h>

#include <inttypes.h>

extern int k1;
extern int k3;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int cur;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW dependency by splitting assignments and reordering writes
    // This creates a Write-After-Write dependency across iterations if unrolled or vectorized
    for (k = k1; k <= k3; k++) {
        dmx[cur][k] = -987654321;
        imx[cur][k] = -987654321;
        mmx[cur][k] = -987654321;
    }
}
