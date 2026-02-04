#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < h; i += 2) {
        for (j = 0; j < 4; j++) {
            if (i + 1 < h) {
                // Process two rows per iteration to increase computational density
                ptrdiff_t curr = i * stride + j;
                ptrdiff_t next = (i + 1) * stride + j;

                // First row update
                dst[curr] = ((dst[curr] + ((A * src[curr] + B * src[curr + 1] + C * src[curr + stride] + D * src[curr + stride + 1] + 32) >> 6) + 1) >> 1);

                // Second row update
                dst[next] = ((dst[next] + ((A * src[next] + B * src[next + 1] + C * src[next + stride] + D * src[next + stride + 1] + 32) >> 6) + 1) >> 1);
            } else {
                // Handle leftover row
                ptrdiff_t curr = i * stride + j;
                dst[curr] = ((dst[curr] + ((A * src[curr] + B * src[curr + 1] + C * src[curr + stride] + D * src[curr + stride + 1] + 32) >> 6) + 1) >> 1);
            }
        }
    }
}
