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
    // Variant 1: Strided memory access with stride of 2
    for (k = k1; k <= k3; k += 2)
        mmx[cur][k] = imx[cur][k] = dmx[cur][k] = -987654321;
}
