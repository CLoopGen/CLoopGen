#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *src_r;
extern uint16_t *src_g;
extern uint16_t *src_b;
extern ptrdiff_t linesize_r;
extern ptrdiff_t linesize_g;
extern ptrdiff_t linesize_b;
extern int width;
extern int height;
extern int r;
extern int g;
extern int b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    for (j = 0; j < height; j++) {
        uint16_t *r_ptr = src_r;
        uint16_t *g_ptr = src_g;
        uint16_t *b_ptr = src_b;
        for (i = 0; i < width - 1; i += 2) {
            // Process two pixels at once to promote consecutive access
            int r0 = r_ptr[i], g0 = g_ptr[i], b0 = b_ptr[i];
            int r1 = r_ptr[i+1], g1 = g_ptr[i+1], b1 = b_ptr[i+1];

            r_ptr[i]   = (r0 + g0 - 512) & 1023;
            b_ptr[i]   = (b0 + g0 - 512) & 1023;
            r_ptr[i+1] = (r1 + g1 - 512) & 1023;
            b_ptr[i+1] = (b1 + g1 - 512) & 1023;
        }
        // Handle remaining pixel if width is odd
        if (i < width) {
            r = src_r[i];
            g = src_g[i];
            b = src_b[i];
            src_r[i] = (r + g - 512) & 1023;
            src_b[i] = (b + g - 512) & 1023;
        }
        src_r += linesize_r;
        src_g += linesize_g;
        src_b += linesize_b;
    }
}
