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
extern  int height;
extern  int xblocks4;
extern int *c_array;
extern int heighta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = heighta; y < height - 1; y += 2) {
    const int temp1 = (y / blocky) * xblocks4;
    const int temp2 = ((y + yhalf) / blocky) * xblocks4;
    for (x = 0; x < width - 3; x += 4) {
        if (cmkp[x - cmk_linesize] == 255 && cmkp[x] == 255 && cmkp[x + cmk_linesize] == 255) {
            const int box1_base = (x / blockx) * 4;
            const int box2_base = ((x + xhalf) / blockx) * 4;
            c_array[temp1 + box1_base] += 1;
            c_array[temp1 + box2_base + 1] += 1;
            c_array[temp2 + box1_base + 2] += 1;
            c_array[temp2 + box2_base + 3] += 1;
        }
        if (cmkp[x + 1 - cmk_linesize] == 255 && cmkp[x + 1] == 255 && cmkp[x + 1 + cmk_linesize] == 255) {
            const int box1_base = ((x + 1) / blockx) * 4;
            const int box2_base = ((x + 1 + xhalf) / blockx) * 4;
            c_array[temp1 + box1_base] += 1;
            c_array[temp1 + box2_base + 1] += 1;
            c_array[temp2 + box1_base + 2] += 1;
            c_array[temp2 + box2_base + 3] += 1;
        }
        if (cmkp[x + 2 - cmk_linesize] == 255 && cmkp[x + 2] == 255 && cmkp[x + 2 + cmk_linesize] == 255) {
            const int box1_base = ((x + 2) / blockx) * 4;
            const int box2_base = ((x + 2 + xhalf) / blockx) * 4;
            c_array[temp1 + box1_base] += 1;
            c_array[temp1 + box2_base + 1] += 1;
            c_array[temp2 + box1_base + 2] += 1;
            c_array[temp2 + box2_base + 3] += 1;
        }
        if (cmkp[x + 3 - cmk_linesize] == 255 && cmkp[x + 3] == 255 && cmkp[x + 3 + cmk_linesize] == 255) {
            const int box1_base = ((x + 3) / blockx) * 4;
            const int box2_base = ((x + 3 + xhalf) / blockx) * 4;
            c_array[temp1 + box1_base] += 1;
            c_array[temp1 + box2_base + 1] += 1;
            c_array[temp2 + box1_base + 2] += 1;
            c_array[temp2 + box2_base + 3] += 1;
        }
    }
    cmkp += cmk_linesize * 2;
}
}
