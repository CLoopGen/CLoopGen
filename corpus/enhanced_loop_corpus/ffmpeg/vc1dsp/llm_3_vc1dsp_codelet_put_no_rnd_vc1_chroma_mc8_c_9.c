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
    // Variant 2: Strided memory access with transposed computation order (process columns first)
    for (i = 0; i < h; i++) {
        for (int j = 0; j < 8; j += 4) {
            // Process 4 elements with increased spatial step to simulate strided traversal effect
            int offset = i * stride + j;
            dst[j + 0] = ((A * src[offset] + B * src[offset + 1] + C * src[offset + stride] + D * src[offset + stride + 1] + 28) >> 6);
            dst[j + 1] = ((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2] + 28) >> 6);
            dst[j + 2] = ((A * src[offset + 2] + B * src[offset + 3] + C * src[offset + stride + 2] + D * src[offset + stride + 3] + 28) >> 6);
            dst[j + 3] = ((A * src[offset + 3] + B * src[offset + 4] + C * src[offset + stride + 3] + D * src[offset + stride + 4] + 28) >> 6);
        }
        dst += stride;
        src += stride;
    }
}
