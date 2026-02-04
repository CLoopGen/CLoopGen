#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h + 4 - 1; y++) {
        int accesses[4] = {1, -1, 2, -2}; // Stride pattern for indirect-like access
        for (x = 0; x < 4; x++) {
            int base_idx = x;
            int idx0 = base_idx + 0;
            int idx1 = base_idx + accesses[0];  // +1
            int idx2 = base_idx + accesses[1];  // -1
            int idx3 = base_idx + accesses[2];  // +2
            int idx4 = base_idx + accesses[3];  // -2
            int idx5 = base_idx + 3;
            tmp[x] = cm[(filter[2] * src[idx0] - filter[1] * src[idx2] + 
                        filter[0] * src[base_idx - 2] + filter[3] * src[idx1] - 
                        filter[4] * src[idx3] + filter[5] * src[idx5] + 64) >> 7];
        }
        tmp += 4;
        src += srcstride;
    }
}
