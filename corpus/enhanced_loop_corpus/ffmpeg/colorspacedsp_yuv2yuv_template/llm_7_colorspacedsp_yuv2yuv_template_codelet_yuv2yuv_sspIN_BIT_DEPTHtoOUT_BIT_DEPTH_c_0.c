#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ptrdiff_t src_stride[3];
extern int w;
extern int h;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int y;
extern int x;
extern  int rnd;
extern int y_off_out;
extern  int uv_off_in;
extern int cyu;
extern int cyv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t stride1 = src_stride[1] / sizeof(uint16_t);
    ptrdiff_t stride2 = src_stride[2] / sizeof(uint16_t);
    uint16_t *s1 = src1;
    uint16_t *s2 = src2;
    int prev_result = y_off_out; // Initialize with base value
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int u = s1[x] - uv_off_in;
            int v = s2[x] - uv_off_in;
            // Make `rnd` depend on previous iteration's result → introduce loop-carried RAW dependency
            int uv_val = cyu * u + cyv * v + rnd + prev_result;
            prev_result = (uv_val >> 4) & 0xFFFF; // Feed output back in next iteration
            s1[x] = prev_result; // Also create WAW by overwriting input data
        }
        s1 += stride1;
        s2 += stride2;
    }
}
