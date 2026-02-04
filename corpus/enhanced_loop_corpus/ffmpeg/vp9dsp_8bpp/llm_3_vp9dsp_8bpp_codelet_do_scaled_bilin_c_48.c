#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int dx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;
extern int imx;
extern int ioff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd element forward and backward in a zigzag pattern
    int stride = 2;
    int half_w = (w + 1) / 2;
    int imx_local = imx;
    int ioff_local = ioff;

    for (x = 0; x < half_w; x++) {
        // Forward strided access
        int idx_forward = ioff_local;
        tmp_ptr[2*x] = (src[idx_forward] + ((imx_local * (src[idx_forward + 1] - src[idx_forward]) + 8) >> 4));
        imx_local += dx;
        ioff_local += imx_local >> 4;
        imx_local &= 15;

        // Backward strided access (mirrored index from end)
        if (2*x + 1 < w) {
            int x_back = w - 1 - 2*x;
            int idx_backward = ioff_local;
            tmp_ptr[x_back] = (src[idx_backward] + ((imx_local * (src[idx_backward + 1] - src[idx_backward]) + 8) >> 4));
            imx_local += dx;
            ioff_local += imx_local >> 4;
            imx_local &= 15;
        }
    }
}
