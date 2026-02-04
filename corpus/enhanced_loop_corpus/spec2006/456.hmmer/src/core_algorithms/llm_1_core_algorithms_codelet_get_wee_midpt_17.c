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
    int j;
    for (j = 0; j < 1; j++) {
        mmx[nxt][k] = imx[nxt][k] = dmx[nxt][k] = -987654321;
    }
}
}
