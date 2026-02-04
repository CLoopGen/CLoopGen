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
for (y = 2; y < yhalf; y += 2) {
    const int temp1 = (y / blocky) * xblocks4;
    const int temp2 = ((y + yhalf) / blocky) * xblocks4;
    for (x = 0; x < width - 1; x++) {
        if (cmkp[x - cmk_linesize] == 255 && cmkp[x] == 255 && cmkp[x + cmk_linesize] == 255 &&
            cmkp[x + 1 - cmk_linesize] == 255 && cmkp[x + 1] == 255 && cmkp[x + 1 + cmk_linesize] == 255) {
            const int box1a = (x / blockx) * 4;
            const int box2a = ((x + xhalf) / blockx) * 4;
            const int box1b = ((x + 1) / blockx) * 4;
            const int box2b = (((x + 1) + xhalf) / blockx) * 4;
            c_array[temp1 + box1a] += 1;
            c_array[temp1 + box2a + 1] += 1;
            c_array[temp2 + box1a + 2] += 1;
            c_array[temp2 + box2a + 3] += 1;
            c_array[temp1 + box1b] += 1;
            c_array[temp1 + box2b + 1] += 1;
            c_array[temp2 + box1b + 2] += 1;
            c_array[temp2 + box2b + 3] += 1;
        }
    }
    cmkp += cmk_linesize * 2;
}
}
