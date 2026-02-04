#include <stdio.h>

#include <inttypes.h>

extern int M;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_val = -987654321;
    for (k = 0; k <= M; k++) {
        imx[0][k] = temp_val;
        dmx[0][k] = imx[0][k];  // RAW dependency: dmx[0][k] reads imx[0][k] just written
        mmx[0][k] = dmx[0][k];  // RAW dependency: mmx[0][k] reads dmx[0][k] just written
    }
}
