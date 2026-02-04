#include <stdio.h>

#include <inttypes.h>

extern int k1;
extern int k3;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int nxt;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int k = k1; k <= k3 + 1; k += 2) {
        mmx[nxt][k] = -987654321;
        imx[nxt][k] = -987654321;
        dmx[nxt][k] = -987654321;
        
        // Handle next element in stride if within bounds
        if (k + 1 <= k3 + 1) {
            mmx[nxt][k+1] = -987654321;
            imx[nxt][k+1] = -987654321;
            dmx[nxt][k+1] = -987654321;
        }
    }
}
