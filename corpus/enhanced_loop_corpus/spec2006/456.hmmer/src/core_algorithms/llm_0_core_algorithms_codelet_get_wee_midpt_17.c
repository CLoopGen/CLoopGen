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
int i;
for (i = 0; i < 1; i++)
    for (k = k1; k <= k3 + 1; k++)
        mmx[nxt][k] = imx[nxt][k] = dmx[nxt][k] = -987654321;
}
