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
for (k = k1; k <= k3; k++) {
    int val = -987654321;
    mmx[nxt][k] = val;
    if (k % 2 == 0) {
        imx[nxt][k] = val;
    } else {
        dmx[nxt][k] = val;
    }
}
for (k = k1; k <= k3; k++) {
    if (k % 2 == 1) {
        imx[nxt][k] = -987654321;
    } else {
        dmx[nxt][k] = -987654321;
    }
}
}
