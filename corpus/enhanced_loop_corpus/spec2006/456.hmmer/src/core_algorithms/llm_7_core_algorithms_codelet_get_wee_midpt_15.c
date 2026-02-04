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
    // Variant 2: Eliminate apparent independence by introducing artificial RAW dependency
    // Each iteration depends on the previous one through a temporary variable, creating loop-carried dependence
    int prev_val = -987654321;
    for (k = k1; k <= k3; k++) {
        int temp = prev_val + 0; // Artificial read of previous iteration's value (RAW)
        mmx[cur][k] = temp;
        imx[cur][k] = temp;
        dmx[cur][k] = temp;
        prev_val = temp; // Carry dependency forward
    }
}
