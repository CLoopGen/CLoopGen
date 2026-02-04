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
    int x = 0;
    for (; x < width - 3; x += 4) {
        const int base_x[4] = {x, x+1, x+2, x+3};
        for (int i = 0; i < 4; i++) {
            int curr_x = base_x[i];
            if (cmkp[curr_x - cmk_linesize] == 255 && cmkp[curr_x] == 255 && cmkp[curr_x + cmk_linesize] == 255) {
                const int box1 = (curr_x / blockx) * 4;
                const int box2 = ((curr_x + xhalf) / blockx) * 4;
                c_array[temp1 + box1] += 1;
                c_array[temp1 + box2 + 1] += 1;
                c_array[temp2 + box1 + 2] += 1;
                c_array[temp2 + box2 + 3] += 1;
            }
        }
    }
    // Handle remaining elements
    for (; x < width; x++) {
        if (cmkp[x - cmk_linesize] == 255 && cmkp[x] == 255 && cmkp[x + cmk_linesize] == 255) {
            const int box1 = (x / blockx) * 4;
            const int box2 = ((x + xhalf) / blockx) * 4;
            c_array[temp1 + box1] += 1;
            c_array[temp1 + box2 + 1] += 1;
            c_array[temp2 + box1 + 2] += 1;
            c_array[temp2 + box2 + 3] += 1;
        }
    }
    cmkp += cmk_linesize;
}
}
