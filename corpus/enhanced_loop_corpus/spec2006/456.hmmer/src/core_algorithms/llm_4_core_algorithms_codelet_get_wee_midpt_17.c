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
for (k = k1; k <= k3 + 1; k++) {
    if (k % 2 == 0) {
        mmx[nxt][k] = -987654321;
        imx[nxt][k] = -987654321;
        dmx[nxt][k] = -987654321;
    } else {
        continue;
    }
}
}
