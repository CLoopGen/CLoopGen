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
        uint8_t* cmkp_current = cmkp + y * cmk_linesize;
        uint8_t* cmkp_prev = cmkp_current - cmk_linesize;
        uint8_t* cmkp_next = cmkp_current + cmk_linesize;
        for (x = 1; x < width - 1; x++) {
            int center_val = cmkp_current[x];
            int above_val = cmkp_prev[x];
            int below_val = cmkp_next[x];
            if (above_val == 255 && center_val == 255 && below_val == 255) {
                const int box1 = (x / blockx) * 4;
                const int box2 = ((x + xhalf) / blockx) * 4;
                c_array[temp1 + box1]++;
                c_array[temp1 + box2 + 1]++;
                c_array[temp2 + box1 + 2]++;
                c_array[temp2 + box2 + 3]++;
            }
        }
    }
}
