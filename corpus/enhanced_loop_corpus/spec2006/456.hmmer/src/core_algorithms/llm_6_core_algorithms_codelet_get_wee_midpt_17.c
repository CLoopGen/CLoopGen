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
    int temp_val = -987654321;
    for (k = k1; k <= k3 + 1; k++) {
        dmx[nxt][k] = temp_val;
        imx[nxt][k] = dmx[nxt][k]; // Introduce RAW dependency: imx depends on dmx
        mmx[nxt][k] = imx[nxt][k]; // Chain dependency: mmx depends on imx
    }
}
