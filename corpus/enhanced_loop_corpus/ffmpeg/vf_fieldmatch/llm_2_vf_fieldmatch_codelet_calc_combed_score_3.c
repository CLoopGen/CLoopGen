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



void loop() {
    for (y = 1; y < yhalf; y++) {
        const int temp1 = (y / blocky) * xblocks4;
        const int temp2 = ((y + yhalf) / blocky) * xblocks4;
        uint8_t* cmk_base = cmkp - cmk_linesize;
        for (x = 0; x < width; x++) {
            if (cmk_base[x] == 255 && cmkp[x] == 255 && cmkp[x + cmk_linesize] == 255) {
                const int box1 = (x / blockx) * 4;
                const int box2 = ((x + xhalf) / blockx) * 4;
                int* base_ptr = c_array;
                base_ptr[temp1 + box1]++;
                base_ptr[temp1 + box2 + 1]++;
                base_ptr[temp2 + box1 + 2]++;
                base_ptr[temp2 + box2 + 3]++;
            }
        }
        cmkp += cmk_linesize;
    }
}
