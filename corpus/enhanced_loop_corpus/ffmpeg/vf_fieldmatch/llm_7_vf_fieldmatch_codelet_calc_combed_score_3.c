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
int prev_temp1 = 0, prev_temp2 = 0;
for (y = 1; y < yhalf; y++) {
    const int temp1 = (y / blocky) * xblocks4;
    const int temp2 = ((y + yhalf) / blocky) * xblocks4;
    int acc_update = 0;
    for (x = 0; x < width; x++) {
        if (cmkp[x - cmk_linesize] == 255 && cmkp[x] == 255 && cmkp[x + cmk_linesize] == 255) {
            const int box1 = (x / blockx) * 4;
            const int box2 = ((x + xhalf) / blockx) * 4;
            acc_update += 4;
            c_array[temp1 + box1] += 1;
            c_array[temp1 + box2 + 1] += 1;
            c_array[temp2 + box1 + 2] += 1;
            c_array[temp2 + box2 + 3] += 1;
        }
    }
    if (acc_update > 0) {
        if (y > 1) {
            c_array[prev_temp1] += acc_update / 4;
        }
        prev_temp1 = temp1;
        prev_temp2 = temp2;
    }
    cmkp += cmk_linesize;
}
}
