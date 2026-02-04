#include <stdio.h>

#include <inttypes.h>

extern int M;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= M; k++) {
    for (int i = 0; i < 1; i++) {
        mmx[0][k] = imx[0][k] = dmx[0][k] = -987654321;
    }
}
}
