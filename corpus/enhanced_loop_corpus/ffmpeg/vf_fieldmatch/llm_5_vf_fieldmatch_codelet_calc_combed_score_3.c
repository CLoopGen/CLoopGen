#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern  int blockx;
extern  int blocky;
extern  int xhalf;
extern  int yhalf;
extern  int cmk_linesize;
extern  uint8_t *cmkp;
extern  int width;
extern  int xblocks4;
extern int *c_array;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < yhalf; y++) {
    const int temp1 = (y / blocky) * xblocks4;
    const int temp2 = ((y + yhalf) / blocky) * xblocks4;
    int updated = 0;
    for (x = 0; x < width; x++) {
        const uint8_t* px = &cmkp[x];
        if (px[-cmk_linesize] != 255) continue;
        if (px[0] != 255) continue;
        if (px[cmk_linesize] != 255) continue;

        const int box1 = (x / blockx) * 4;
        const int box2 = ((x + xhalf) / blockx) * 4;
        c_array[temp1 + box1] += 1;
        c_array[temp1 + box2 + 1] += 1;
        c_array[temp2 + box1 + 2] += 1;
        c_array[temp2 + box2 + 3] += 1;
        updated = 1;
    }
    if (updated) {
        cmkp += cmk_linesize;
    } else {
        cmkp += cmk_linesize;
    }
}
}
