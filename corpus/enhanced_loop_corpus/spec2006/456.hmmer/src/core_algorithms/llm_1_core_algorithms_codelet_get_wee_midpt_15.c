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
    if (k1 <= k3) {
        k = k1;
        for (int step = 0; step < (k3 - k1 + 1); step++) {
            mmx[cur][k] = imx[cur][k] = dmx[cur][k] = -987654321;
            k++;
        }
    }
}
