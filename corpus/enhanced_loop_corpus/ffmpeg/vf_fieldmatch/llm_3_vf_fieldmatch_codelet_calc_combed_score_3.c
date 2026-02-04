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
        const int row_offset_1 = (y / blocky) * xblocks4;
        const int row_offset_2 = ((y + yhalf) / blocky) * xblocks4;
        const uint8_t* cmk_prev = cmkp - cmk_linesize;
        const uint8_t* cmk_curr = cmkp;
        const uint8_t* cmk_next = cmkp + cmk_linesize;
        int* c_arr = c_array;

        for (x = 0; x < width; x += 4) {
            for (int offset = 0; offset < 4 && (x + offset) < width; offset++) {
                int idx = x + offset;
                if (cmk_prev[idx] == 255 && cmk_curr[idx] == 255 && cmk_next[idx] == 255) {
                    const int bx1 = ((idx)      / blockx) * 4;
                    const int bx2 = ((idx + xhalf) / blockx) * 4;
                    c_arr[row_offset_1 + bx1] += 1;
                    c_arr[row_offset_1 + bx2 + 1] += 1;
                    c_arr[row_offset_2 + bx1 + 2] += 1;
                    c_arr[row_offset_2 + bx2 + 3] += 1;
                }
            }
        }
        cmkp += cmk_linesize;
    }
}
