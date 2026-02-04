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
    const uint8_t* cmk_prev = cmkp + (y - 1) * cmk_linesize;
    const uint8_t* cmk_curr = cmkp + y * cmk_linesize;
    const uint8_t* cmk_next = cmkp + (y + 1) * cmk_linesize;
    for (x = 0; x < width; x++) {
        if (cmk_prev[x] == 255 && cmk_curr[x] == 255 && cmk_next[x] == 255) {
            const int box1 = (x / blockx) << 2;           // Equivalent to *4 via bit shift
            const int box2 = ((x + xhalf) / blockx) << 2;
            int* base_ptr = c_array;
            base_ptr[temp1 + box1] += 1;
            base_ptr[temp1 + box2 + 1] += 1;
            base_ptr[temp2 + box1 + 2] += 1;
            base_ptr[temp2 + box2 + 3] += 1;
        }
    }
}
}
