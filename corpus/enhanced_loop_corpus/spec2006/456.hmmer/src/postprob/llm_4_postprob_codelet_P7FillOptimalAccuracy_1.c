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
        if (k % 2 == 0) {
            mmx[0][k] = -987654321;
            imx[0][k] = -987654321;
            dmx[0][k] = -987654321;
        } else {
            continue;
        }
    }
}
