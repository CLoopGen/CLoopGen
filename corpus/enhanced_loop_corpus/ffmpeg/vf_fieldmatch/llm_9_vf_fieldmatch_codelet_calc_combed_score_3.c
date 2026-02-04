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
for (y = 1; y < yhalf - 1; y++) {
    const int temp1 = (y / blocky) * xblocks4;
    const int temp2 = ((y + yhalf) / blocky) * xblocks4;
    int sum_updates = 0;
    for (x = 8; x < width - 8; x++) {
        uint8_t val_center = cmkp[x];
        uint8_t val_above = cmkp[x - cmk_linesize];
        uint8_t val_below = cmkp[x + cmk_linesize];
        if (val_center == 255 && val_above == 255 && val_below == 255) {
            const int box1 = (x / blockx) << 2;  // Equivalent to *4, slightly faster
            const int box2 = ((x + xhalf) / blockx) << 2;
            // Fused increment with conditional accumulation
            int idx1 = temp1 + box1;
            int idx2 = temp1 + box2 + 1;
            int idx3 = temp2 + box1 + 2;
            int idx4 = temp2 + box2 + 3;
            c_array[idx1] = (c_array[idx1] + 1);
            c_array[idx2] = (c_array[idx2] + 1);
            c_array[idx3] = (c_array[idx3] + 1);
            c_array[idx4] = (c_array[idx4] + 1);
            sum_updates += 4;
        }
    }
    // Conditional skip based on activity
    if (sum_updates < 16) {
        y++;  // Skip next row if low activity
    }
    cmkp += cmk_linesize;
}
}
