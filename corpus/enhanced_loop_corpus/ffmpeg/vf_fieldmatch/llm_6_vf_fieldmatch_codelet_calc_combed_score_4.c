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
    for (y = heighta; y < height - 1; y++) {
        const int temp1 = (y / blocky) * xblocks4;
        const int temp2 = ((y + yhalf) / blocky) * xblocks4;
        uint8_t* cmkp_offset = cmkp + y * cmk_linesize;
        for (x = 1; x < width - 1; x++) {
            if (cmkp_offset[x - cmk_linesize] == 255 && cmkp_offset[x] == 255 && cmkp_offset[x + cmk_linesize] == 255) {
                const int box1 = (x / blockx) * 4;
                const int box2 = ((x + xhalf) / blockx) * 4;
                int idx1 = temp1 + box1;
                int idx2 = temp1 + box2 + 1;
                int idx3 = temp2 + box1 + 2;
                int idx4 = temp2 + box2 + 3;
                c_array[idx1] += 1;
                c_array[idx2] += 1;
                c_array[idx3] += 1;
                c_array[idx4] += 1;
            }
        }
    }
}
