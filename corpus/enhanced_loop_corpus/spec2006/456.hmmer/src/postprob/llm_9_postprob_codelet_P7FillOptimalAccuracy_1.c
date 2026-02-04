#include <stdio.h>

#include <inttypes.h>

extern int M;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= M; k += 2) {
    int val = -987654321;
    mmx[0][k] = imx[0][k] = dmx[0][k] = val;
    if (k + 1 <= M) {
        mmx[0][k+1] = imx[0][k+1] = dmx[0][k+1] = val;
    }
}
}
