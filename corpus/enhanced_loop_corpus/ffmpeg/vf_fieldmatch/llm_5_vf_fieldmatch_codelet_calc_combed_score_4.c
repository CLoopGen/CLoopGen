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
    int processed = 0;
    for (x = 0; x < width; x++) {
        uint8_t val_prev = cmkp[x - cmk_linesize];
        uint8_t val_curr = cmkp[x];
        uint8_t val_next = cmkp[x + cmk_linesize];
        
        if (val_prev == 255 && val_curr == 255 && val_next == 255 && !processed) {
            for (int offset = 0; offset < width; offset += blockx) {
                const int box1 = (offset / blockx) * 4;
                const int box2 = ((offset + xhalf) / blockx) * 4;
                c_array[temp1 + box1] += 1;
                c_array[temp1 + box2 + 1] += 1;
                c_array[temp2 + box1 + 2] += 1;
                c_array[temp2 + box2 + 3] += 1;
            }
            processed = 1;
        }
    }
    cmkp += cmk_linesize;
}
}
