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
int target = k3 + 1;
for (k = k1; k <= target; k++) {
    if (k >= k1) {
        mmx[nxt][k] = imx[nxt][k] = dmx[nxt][k] = -987654321;
    }
}
}
