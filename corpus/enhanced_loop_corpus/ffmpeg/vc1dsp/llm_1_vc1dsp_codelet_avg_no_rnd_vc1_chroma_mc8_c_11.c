#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_iterations = h * 8;
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < total_iterations; i++) {
        int row = i / 8;
        int col = i % 8;
        ptrdiff_t offset = row * stride;
        local_dst[col] = (((local_dst[col]) + (((A * local_src[col] + B * local_src[col + 1] + 
                              C * local_src[stride + col] + D * local_src[stride + col + 1] + 32 - 4) >> 6)) + 1) >> 1);
        if (col == 7) {
            local_dst += stride;
            local_src += stride;
        }
    }
}
