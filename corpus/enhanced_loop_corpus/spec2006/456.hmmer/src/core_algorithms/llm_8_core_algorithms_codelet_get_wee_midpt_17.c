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
int temp1, temp2, temp3;
for (k = k1; k <= k3 + 3; k += 2) {
    temp1 = -987654321 * 2 + k;
    temp2 = -987654321 - k;
    temp3 = -987654321 ^ k;
    mmx[nxt][k] = temp1;
    imx[nxt][k] = temp2;
    dmx[nxt][k] = temp3;
}
}
